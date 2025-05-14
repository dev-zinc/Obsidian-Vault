- Vertex
	- Pos
	- Normal (Vector)
	- TexC (float2)
		- Texture Coordinate
		- texture의 좌표값
		- 3차원 시 (u, v, w) 사용
- Sampling
	- 이미지를 오브젝트에 맞추어 Interpolation mapping

- uv 좌표계
	- Texture에서의 좌표계![[Pasted image 20250514121718.png]]
	- 구 형태의 오브젝트 또한 직사각형의 리소스를 사용
		- (0, 0) == (1, 0)으로 interpolation 실행

- Texture에서도 일종의 Rasterization 가능
- texel: texture의 요소
## DDS
- DirectDraw Surface
- 오브젝트, 텍스쳐 파일
- mipmap, texture array 등 포함

- SRV
	- Shader Resource View

- magnification
	- 가중치로 내분점 찍기
- minification
	- point filtering
	- linear filtering
- Anisotropic filtering
	- 왜곡이 심한 면에 대한 현실적인 밉 레벨 적용![[Pasted image 20250514125215.png]]
- Address Mode
	- Wrap
	- Mirror
	- Clamp
	- Border
	- Mirror-Once

이러한 리소스 데이터는 Sampler의 형식으로 DX에 전달된다.

