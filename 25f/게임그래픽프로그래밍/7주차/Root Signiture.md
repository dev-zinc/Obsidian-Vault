어떤 형식, 함수, 구조 등의 프로토타입

DX에서는 파이프라인 상 Desc Table 등 자원 할당의 구조를 정의

---
```hlsl
// Texture resource bound to texture register slot 0. 
Texture2D gDiffuseMap : register(t0);
```
---
![[Pasted image 20250416122745.png]]
이렇게 정의해놓고 이후 여기다가 Heap을 할당
