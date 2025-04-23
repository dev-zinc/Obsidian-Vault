`FrameResource(ID3D12Device* device, UINT passCount, UINT objectCount);`

`std::unique_ptr<UploadBuffer<PassConstants>> PassCB = nullptr; std::unique_ptr<UploadBuffer<ObjectConstants>> ObjectCB = nullptr;`

각 오브젝트마다 하나의 World 좌표계를 가짐
따라서 오브젝트마다 레지스터를 따로 가지며 WVP 등도 각각 할당함

`// Cycle through the circular frame resource array.` 
`mCurrFrameResourceIndex = (mCurrFrameResourceIndex + 1) % gNumFrameResources;` 
`mCurrFrameResource = mFrameResources[mCurrFrameResourceIndex].get();`

Circleur Queue를 통해 관리

