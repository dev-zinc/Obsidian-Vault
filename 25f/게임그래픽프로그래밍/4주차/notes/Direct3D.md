## Features
- `shader model, raytracing, mesh shader, resource binding` 등을 지원하는가에 대한 범위 설정
## Initialization Steps
1. Create the ID3D12Device using the D3D12CreateDevice function. `D3D12CreateDevice`를 통해 디바이스 생성
2. Create an ID3D12Fence object and query descriptor sizes. 펜스 생성, 디스크립터의 크기 전달
3. Check 4X MSAA quality level support. MSAA 체크
4. Create the command queue, command list allocator, and main command list. 커맨드 관련 오브젝트 생성
5. Describe and create the swap chain. 스왑 체인 생성
6. Create the descriptor heaps the application requires. 디스크립터 힙을 생성
7. Resize the back buffer and create a render target view to the back buffer. 백 버퍼를 리사이징 후 그곳에 RTV 생성
8. Create the depth/stencil buffer and its associated depth/stencil view. DS buffer와 그의 DSV 생성
9. Set the viewport and scissor rectangles. 뷰포트 설정