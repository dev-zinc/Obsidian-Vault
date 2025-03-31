### RTV
- render target view
### DSV 
- depth stencil view
### CBV 
- constant buffer view
- Shader constant data. 
- Typical data would be world, projection, and view matrices. 
### SRV 
- shader resource view
- SRVs typically wrap textures in a format that the shaders can access them.
### UAV
- unordered access view
- An UAV provides similar functionality but enables the reading and writing to the texture (or other resource) in any order.
### VBV
- vertex buffer view
### IBV 
- index buffer view
### SOV 
- stream output view

## Viewport
- 일종의 subscreen
- `ID3D11DeviceContext::RSSetViewports`
- `ID3D11DeviceContext::RSSetScissorRects`
