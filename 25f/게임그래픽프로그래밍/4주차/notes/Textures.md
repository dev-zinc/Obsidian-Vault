- 2D textures
- matrix 형태

### DXGI Format
- DirectX Graphics Infrastructure
	- DXGI_FORMAT_R32G32B32_float
	- DXGI_FORMAT_R16G16B16A16_UNORM 
		- \[0, 1]로 매핑
	- DXGI_FORMAT_R32G32_UINT
	- DXGI_FORMAT_R8G8B8A8_UNORM
		-  \[0, 1]로 매핑
	- DXGI_FORMAT_R8G8B8A8_SNORM 
		-  \[-1, 1]로 매핑
	- DXGI_FORMAT_R8G8B8A8_SINT
		-  \[-128, 127]로 매핑
	- DXGI_FORMAT_R8G8B8A8_UINT
		-  \[0, 255]로 매핑
	- DXGI_FORMAT_R16G16B16A16_TYPELESS
- U: unsigned
- S: signed
- NORM: normalized
### Swap Chain & Page Fliping
- 화면 깜빡임 방지를 위해 버퍼를 여럿 사용하는 것
- '미리' 그려놓기
- Front Buffer
	- 현재 화면의 버퍼
- Back Buffer
	- 이 다음 화면의 버퍼
	- 백 버퍼에 렌더링 후 교체하는 방식 사용
### Depth Buffer
- z value에 대한 버퍼 (z-buffering)
- normalize하여 사용한다.
- 초기에 1이며, 먼 오브젝트부터 렌더링하며 z buffer의 depth를 해당 오브젝트의 depth로 업데이트한다.
### Stencil Buffer
이펙트 표현할 때 픽셀 마스킹에 사용
#### MIP Levels
- mip-maps / mip-pyramids
- 이전 이미지의 낮은 resoultion 
