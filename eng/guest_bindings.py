"""Static C11 typed bindings for the complete ABI catalog; imported by generator."""
import re

def generate(spec, schema_fingerprints):
    models = dict(spec['models'])
    def name(t): return t.replace('[]','Array').replace('?','Optional').replace('<','_').replace('>','')
    def add(t):
        if t.endswith('?'): add(t[:-1])
        elif t.endswith('[]'): add(t[:-2])
        elif t.startswith('Page<'):
            inner=t[5:-1]; add(inner); models[t]=[{'name':'Items','type':inner+'[]'},{'name':'NextCursor','type':'string?'},{'name':'Revision','type':'Revision'}]
        elif t.startswith('Snapshot<'):
            inner=t[9:-1]; add(inner); models[t]=[{'name':'Value','type':inner},{'name':'Revision','type':'Revision'},{'name':'SchemaVersion','type':'ulong'},{'name':'ObservedAt','type':'DateTimeOffset'}]
    for g in spec['groups']:
        for op in g['operations']: add(op['input']);add(op['output'])
    types=set(models)|set(spec['enums'])
    for fs in models.values():
        for f in fs: types.add(f['type'])
    for t in list(types):
        while t.endswith('?') or t.endswith('[]'):
            t=t[:-1] if t.endswith('?') else t[:-2]; types.add(t)
    types=sorted(types)
    scalar={'string':'nx_text','Guid':'nx_text','DateTimeOffset':'nx_text','QualifiedId':'nx_text','EntityId':'nx_text','Revision':'nx_text','UriRef':'nx_text','int':'nx_i64','uint':'nx_u64','bool':'int','long':'nx_i64','ulong':'nx_u64','double':'nx_f64','AbiValue':'nx_value'}
    def ctype(t): return scalar.get(t,'nx_'+name(t))
    def read(t,v): return 'nx_'+name(t)+'_read('+v+')'
    def encode(t,v): return 'nx_'+name(t)+'_encode(w,'+v+');'
    out=['/* Generated; do not edit. Borrowed typed views; no allocation or system imports. */','#ifndef NEXA_ABI100_H','#define NEXA_ABI100_H','#include "guest.h"','#include "abi100_ids.h"']
    for t in types:
        if t in spec['enums']:
            out.append('typedef enum { '+', '.join('nx_'+t+'_'+e+' = '+str(i) for i,e in enumerate(spec['enums'][t]))+' } nx_'+t+';')
        elif t not in scalar: out.append('typedef struct { nx_value value; } '+ctype(t)+';')
    for t in types:
        n=name(t);ct=ctype(t)
        out.extend([f'static inline void nx_{n}_validate(nx_value v, nx_u32 depth);',f'static inline {ct} nx_{n}_read(nx_value v);',f'static inline void nx_{n}_encode(nx_writer *w, {ct} value);'])
    for t in types:
        n=name(t);ct=ctype(t)
        body='nx_require(depth <= 32); '
        if t.endswith('?'): body+=f'if (!nx_is_null(v)) nx_{name(t[:-1])}_validate(v,depth+1);'
        elif t.endswith('[]'):
            body+='nx_u32 count=nx_count(v); '+f'for(nx_u32 i=0;i<count;i++) nx_{name(t[:-2])}_validate(nx_at(v,i),depth+1);'
        elif t in models:
            body+='nx_require(v.size && v.data[0]==8); '
            for f in models[t]:
                key=f['name'][0].lower()+f['name'][1:];body+=f'nx_{name(f["type"])}_validate(nx_field(v,"{key}"),depth+1); '
                if 'constant' in f: body+=f'nx_require(nx_is_string(nx_field(v,"{key}"),"{f["constant"]}")); '
        elif t in spec['enums']: body+='nx_require('+' || '.join(f'nx_is_string(v,"{e}")' for e in spec['enums'][t])+');'
        elif t in ['bool','long','ulong','double','int','uint']:
            body+='(void)'+{'int':'nx_as_signed','uint':'nx_as_unsigned','bool':'nx_as_boolean','long':'nx_as_signed','ulong':'nx_as_unsigned','double':'nx_as_float'}[t]+'(v);'
        elif t=='AbiValue': body+='nx_reader r={v.data,v.size,0,0}; nx_skip(&r,depth); nx_require(r.offset==r.size);'
        else:
            body+='nx_text text=nx_as_text(v); nx_utf8(text.data,text.size); '
            if t in ['EntityId','Revision']: body+='nx_require(text.size>0 && nx_utf8(text.data,text.size)<=1024);'
            elif t=='QualifiedId': body+='nx_qualified_id(text);'
            elif t=='Guid': body+='nx_guid(text);'
            elif t=='DateTimeOffset': body+='nx_timestamp(text);'
            elif t=='UriRef': body+='nx_uri(text);'
        if t=='int': body+='nx_i64 i=nx_as_signed(v); nx_require(i>=(-2147483647LL-1) && i<=2147483647LL);'
        if t=='uint': body+='nx_require(nx_as_unsigned(v)<=4294967295ULL);'
        out.append(f'static inline void nx_{n}_validate(nx_value v,nx_u32 depth) {{ {body} }}')
        body=f'nx_{n}_validate(v,0); '
        if t in spec['enums']:
            body+=' '.join(f'if(nx_is_string(v,"{e}")) return nx_{t}_{e};' for e in spec['enums'][t])+f' __builtin_trap();'
        elif t not in scalar: body+=f'{ct} result={{v}}; return result;'
        elif t=='AbiValue': body+='return v;'
        else: body+='return '+{'int':'nx_as_signed','uint':'nx_as_unsigned','bool':'nx_as_boolean','long':'nx_as_signed','ulong':'nx_as_unsigned','double':'nx_as_float'}.get(t,'nx_as_text')+'(v);'
        out.append(f'static inline {ct} nx_{n}_read(nx_value v) {{ {body} }}')
        if t not in scalar and t not in spec['enums']: body='nx_raw(w,value.value);'
        elif t in spec['enums']: body='switch(value) { '+' '.join(f'case nx_{t}_{e}: nx_string(w,"{e}"); return;' for e in spec['enums'][t])+' default: __builtin_trap(); }'
        else: body={'int':'nx_signed','uint':'nx_unsigned','bool':'nx_boolean','long':'nx_signed','ulong':'nx_unsigned','double':'nx_float','AbiValue':'nx_raw'}.get(t,'nx_text_write')+'(w,value);'
        out.append(f'static inline void nx_{n}_encode(nx_writer *w,{ct} value) {{ {body} }}')
    for t in types:
        n=name(t);ct=ctype(t)
        if t in models:
            for f in models[t]:
                key=f['name'][0].lower()+f['name'][1:]
                out.append(f'static inline {ctype(f["type"])} nx_{n}_{f["name"]}({ct} value) {{ return {read(f["type"],f"nx_field(value.value,\"{key}\")")}; }}')
            params=', '.join(ctype(f['type'])+' arg_'+f['name'] for f in models[t])
            body=f'nx_u32 start=w->size; nx_map(w,{len(models[t])}); '
            for f in sorted(models[t],key=lambda f:f['name'][0].lower()+f['name'][1:]):
                key=f['name'][0].lower()+f['name'][1:];body+=f'nx_key(w,"{key}"); '+encode(f['type'],'arg_'+f['name'])
            body+=f'return nx_{n}_read(nx_written(w,start));'
            out.append(f'static inline {ct} nx_{n}_write(nx_writer *w{", " if params else ""}{params}) {{ {body} }}')
        elif t.endswith('[]'):
            elem=t[:-2];ec=ctype(elem)
            out.extend([f'static inline nx_u32 nx_{n}_count({ct} v) {{ return nx_count(v.value); }}',f'static inline {ec} nx_{n}_at({ct} v,nx_u32 i) {{ return {read(elem,"nx_at(v.value,i)")}; }}',f'static inline {ct} nx_{n}_write(nx_writer *w,const {ec} *items,nx_u32 count) {{ nx_u32 start=w->size; nx_require(count==0 || items); nx_array(w,count); for(nx_u32 i=0;i<count;i++) {{ {encode(elem,"items[i]")} }} return nx_{n}_read(nx_written(w,start)); }}'])
        elif t.endswith('?'):
            elem=t[:-1]
            out.extend([f'static inline int nx_{n}_has_value({ct} v) {{ return !nx_is_null(v.value); }}',f'static inline {ctype(elem)} nx_{n}_value({ct} v) {{ return {read(elem,"v.value")}; }}',f'static inline {ct} nx_{n}_none(nx_writer *w) {{ nx_u32 start=w->size; nx_null(w); return nx_{n}_read(nx_written(w,start)); }}',f'static inline {ct} nx_{n}_some(nx_writer *w,{ctype(elem)} value) {{ nx_u32 start=w->size; {encode(elem,"value")} return nx_{n}_read(nx_written(w,start)); }}'])
    dispatch=[]
    for g in spec['groups']:
        for op in g['operations']:
            fn='nx_'+g['name'].replace('.','_')+'_'+op['name']; inp=op['input'];result=op['output']
            if inp in scalar:
                if inp != 'UriRef': raise ValueError('Add a direct scalar invocation encoder for ' + inp)
                body=f'nx_uri(request); nx_invoke_text_options(w,"{g["contractId"]}",{op["methodId"]},request,options);'
            else: body=f'nx_{name(inp)}_validate(request.value,0); nx_invoke_options(w,"{g["contractId"]}",{op["methodId"]},request.value,options);'
            out.append(f'static inline void {fn}(nx_writer *w,{ctype(inp)} request,const nx_call_options *options) {{ {body} }}')
            out.append(f'static inline int {fn}_result(nx_value reply,{ctype(result)} *result) {{ nx_require(result!=0); *result=({ctype(result)}){{0}}; if(!nx_reply_success(reply)) return 0; *result={read(result,"nx_field(reply,\"value\")")}; return 1; }}')
            i=len(dispatch);dispatch.append((i,fn,inp,result))
    for model,digest in sorted(schema_fingerprints.items()):
        out.append(f'static inline nx_SchemaRef nx_schema_{model}(nx_writer *w) {{ return nx_SchemaRef_write(w,nx_literal("nexa:abi100/{model.lower()}"),1,nx_literal("{digest}")); }}')
    out.append('typedef struct { const char *group, *name, *contract, *input, *output, *kind, *permission, *idempotency, *host_binding; nx_u32 method, phase_count; const char *phases[8]; } nx_operation_descriptor;')
    out.append('static const nx_operation_descriptor nx_operation_catalog[] = {')
    import json
    for group in spec['groups']:
        for operation in group['operations']:
            strings=[group['name'],operation['name'],group['contractId'],operation['input'],operation['output'],operation.get('kind','Legacy'),operation.get('permission',''),operation.get('idempotency','Unspecified'),operation.get('hostBinding','HostMappingPending')]
            phases=operation.get('phases',[])
            out.append('    {'+', '.join(json.dumps(s) for s in strings)+f', {operation["methodId"]}, {len(phases)}, '+'{'+(', '.join(json.dumps(p) for p in phases) if phases else '0')+'}},')
    out.extend(['};','static inline nx_u32 nx_operation_count(void) { return (nx_u32)(sizeof nx_operation_catalog / sizeof nx_operation_catalog[0]); }','static inline const nx_operation_descriptor *nx_operation_at(nx_u32 index) { nx_require(index<nx_operation_count()); return &nx_operation_catalog[index]; }'])
    out.append('#endif')
    test=['/* Generated cross-language conformance guest. */','#include <nexa/abi100.h>','static nx_u8 input[262144],output[262144],scratch[262144];','static nx_u32 operation; static int waiting;','NX_EXPORT("nexa_alloc") nx_u32 alloc(nx_u32 size) { nx_require(size<=sizeof input); return (nx_u32)(__UINTPTR_TYPE__)input; }',
          'NX_EXPORT("nexa_resume") nx_u64 resume(nx_u32 address,nx_u32 size) { nx_require(address==(nx_u32)(__UINTPTR_TYPE__)input && size<=sizeof input); nx_value value=nx_decode(input,size); nx_writer writer={output,0,sizeof output}; nx_writer *w=&writer;',
          'if(!waiting) { operation=(nx_u32)nx_as_unsigned(nx_field(value,"index")); nx_value args=nx_field(value,"arguments");',
          f'if(operation>={len(dispatch)}) {{ nx_writer constructed={{scratch,0,sizeof scratch}}; switch(operation) {{']
    for index,t in enumerate(sorted(models)):
        n=name(t); fields=', '.join(f'nx_{n}_{f["name"]}(model)' for f in models[t])
        test.append(f'case {len(dispatch)+index}: {{ {ctype(t)} model=nx_{n}_read(args); (void)model; {ctype(t)} copy=nx_{n}_write(&constructed{", " if fields else ""}{fields}); nx_complete_value(w,copy.value); break; }}')
    test += ['default: __builtin_trap(); } return nx_result(w); } nx_call_options options={"12345678-1234-1234-1234-123456789abc","conformance","revision",0,1000}; switch(operation) {']
    for i,fn,inp,result in dispatch: test.append(f'case {i}: {fn}(w,{read(inp,"args")},&options); break;')
    test+=['default: __builtin_trap(); } waiting=1; } else { waiting=0; switch(operation) {']
    for i,fn,inp,result in dispatch:test.append(f'case {i}: {{ {ctype(result)} result; if({fn}_result(value,&result)) nx_complete_value(w,{"result" if result=="AbiValue" else "result.value"}); else nx_complete_value(w,nx_reply_error(value)); break; }}')
    test+=['default: __builtin_trap(); } } return nx_result(w); }']
    return '\n'.join(out)+'\n','\n'.join(test)+'\n'
