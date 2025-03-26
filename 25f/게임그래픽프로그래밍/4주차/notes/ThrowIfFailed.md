디버깅을 위한 Macro

- 매크로는 한 line이어야 하므로 "\\"를 사용하여 한 line으로 처리한다.
- 매크로 매개변수는 단순 치환되는 형태로 사용된다. 

```cpp
// d3dUtil.h 
#ifndef ThrowIfFailed
#define ThrowIfFailed(x)                                              \
{                                                                     \
	HRESULT hr__ = (x);                                               \
	std::wstring wfn = AnsiToWString(__FILE__);                       \
	if(FAILED(hr__)) { throw DxException(hr__, L#x, wfn, __LINE__); } \ 
}
```

[(x) 를 사용하는 이유](https://wn42.tistory.com/99#%EB%A-%A-%ED%--%AC%EB%A-%-C%--%ED%--%A-%EC%--%--%--%EC%-C%A-%EC%-D%--%EC%A-%--)

- \_\_FILE__
	- 현재 파일 이름에 대한 매크로
- \_\_LINE__
	- 해당 매크로를 사용한 라인의 위치
- L#x
	- 해당 코드의 문자열 값
	```cpp
		ThrowIfFailed(md3dDevice->CheckFeatureSupport( 
				D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, 
				&msQualityLevels, 
				sizeof(msQualityLevels)
		));
	```
	와 같이 사용 시, 
	- `#x : "md3dDevice->CheckFeatureSupport( D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &msQualityLevels, sizeof(msQualityLevels))"` 
	- L을 사용하여 wide char로 사용
	- 오류 시 출력하기 위해 사용