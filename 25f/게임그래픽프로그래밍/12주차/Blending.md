- F: masking factor

- src: modify factor
- dst: original

- Blend Operator
	- `D3D12_BLEND_OP`
	- `D3D12_LOGIC_OP`
- Blend Factor
	- PS, RT값 조정
- Blend State
	- PSO의 Descriptor에서 `D3D12_BLEND_DESC`타입의 `BlendState`를 지정 가능
- HLSL Defines 전달 시 마지막에 NULL, NULL를 넣어줘야 함