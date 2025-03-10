Windows API가 제공하는 데이터 최적화 형식

```C++
// Stores an XMVECTOR in an XMFLOAT3
void XM_CALLCONV XMStoreFloat3 (XMFLOAT3 *pDestination, FXMVECTOR V) noexcept;

...

#if _XM_VECTORCALL_
#define XM_CALLCONV __vectorcall

```