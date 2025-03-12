CPU연산 시 사용

GPU에서 연산 시에는 (또는 GPU로 전송 시) `XMFLOAT2, XMFLOAT3 ...` 등을 사용 

형식 바꿔줄 때 각각 `XMStoraFloatn, XMLoadFloatn` method 사용

기본적으로,

- 각 Object가 가지는 ModelMatrix
- 카메라가 가지는 ViewMatrix

등의 차원이 존재한다.

행렬연산 시 pre-multiplication(벡터를 먼저 곱함, xA).
