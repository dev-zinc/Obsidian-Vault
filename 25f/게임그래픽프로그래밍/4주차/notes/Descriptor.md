- GPU 자원에 대한 직접적 사용을 하지 않고, Descriptor 객체를 통해 GPU의 인터페이스를 사용하게 된다.
- `~~_DESC`
	- 해당 구조체가 자원을 조작함을 뜻함
### Descriptor 종류
- Render target views (RTVs)
	- RTV Descriptor
- Depth stencil views (DSV)
	- DSV descriptor
- Samplers (used in texturing)
	- sampler descriptor

각각의 View에 대한 Descriptor가 존재한다.

- Constant buffer views (CBVs)
- unordered access views (UAVs)
- shader resource views (SRVs)
### Resources
- Buffers
- Textures