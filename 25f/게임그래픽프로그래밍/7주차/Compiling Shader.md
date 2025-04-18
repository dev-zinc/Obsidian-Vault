```cpp
//d3dUtil.cpp

HRESULT D3DCompileFromFile( 
	[in] LPCWSTR filename, 
	[in, optional] const D3D_SHADER_MACRO *pDefines,
	[in, optional] ID3DInclude *pInclude, 
	[in] LPCSTR pEntrypoint, 
	[in] LPCSTR pTarget, 
	[in] UINT Flags1, 
	[in] UINT Flags2, 
	[out] ID3DBlob **ppCode, 
	[out, optional] ID3DBlob **ppErrorMsgs 
);

...

ComPtr<ID3DBlob> d3dUtil::CompileShader( 
	const std::wstring& filename, 
	const D3D_SHADER_MACRO* defines,
	const std::string& entrypoint, 
	const std::string& target
) { 
	UINT compileFlags = 0; 
	#if defined(DEBUG) || defined(_DEBUG) 
		compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION; 
	#endif
		HRESULT hr = S_OK; 
	ComPtr<ID3DBlob> byteCode = nullptr; 
	ComPtr<ID3DBlob> errors; 
	hr = D3DCompileFromFile(
		filename.c_str(), defines, D3D_COMPILE_STANDARD_FILE_INCLUDE, entrypoint.c_str(),
		target.c_str(), compileFlags, 0, &byteCode, &errors
	); 
	if(errors != nullptr) 
		OutputDebugStringA((char*)errors->GetBufferPointer()); 
	ThrowIfFailed(hr); return byteCode; 
}
```
`D3D_SHADER_MACRO`를 통해 여러 정의된 Shader 중 하나를 전처리문을 통해 사용하도록 할 수 있다.

## FXC tool
- Shader Compiler
- `.hlsl` $\rightarrow$ `.cso`, `.asm`
- VS와 PS 중 하나의 진입점을 선택하여 컴파일 할 수 있다. 

> [!Quote] Options
> - `/Od`: Disable optimizations. `/Od` implies `/Gfp`, though output may not be identical to `/Od /Gfp`.
> - `/O0` `/O1`, `/O2`, `/O3`: Optimization levels. O1 is the default setting. 
> 	- `/O0`: Disables instruction reordering. 
> 	- `/O1`: Disables instruction reordering for ps_3_0 and up. 
> 	- `/O2`: Same as O1. Reserved for future use. 
> 	- `/O3`: Same as O1. Reserved for future use. 
> - `/Zi`: Enable debugging information. 
> - `/T <profile>`: Shader type and target version. 
> - `/E <name>`: Shader entry point. 
> - `/Fo <file>`: Output object file 
> - `/Fc <file>`: Output assembly code listing file.

```cmd
> fxc “color.hlsl” /Od /Zi /T vs_5_0 /E “VS” /Fo “color_vs.cso” /Fc “color_vs.asm”
> fxc “color.hlsl” /Od /Zi /T ps_5_0 /E “PS” /Fo “color_ps.cso” /Fc “color_ps.asm”
```