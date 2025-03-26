### Stair-step (aliasing) effect
- 확대 시 픽셀이 계단처럼 깨지는 현상 (Stair-step)
- ![[Stair-step.png]]
- 축소 시 정보가 뭉개지는 현상 (aliasing)
- ![[Aliasing.png]]

### MSAA
- multi-sample anti aliasing
- view의 버퍼를 4배 크게 하는 것(supersampling)

DirectX12에서는 CheckFeatureSupport를 사용하여 지원 여부를 확인할 수 있다.
```
	HRESULT:S_OK(0x00000000), 0x8xxxxxxx(E_ABORT, E_FAIL, …)
		* 0x8xxxxxxx => 앞자리가 1, signed에서 음수 표현
```
`HRESULT`가 0이거나 양수이면 OK, 음수이면 FAIL이다.

