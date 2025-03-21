# Transformation
DirectX에서는 벡터를 먼저 곱하는 pre-multiplication을 채택하고 있다.
$$

$$
## Affine Transformation
$$\alpha(\textbf{u}) = \tau(\textbf{u}) + \textbf{b}$$
선형 변환 + 변형
# Scaling
# Rotation
벡터 $\textbf{v}$에 대하여 기저 $\textbf{n}$을 기준으로 하여 $\theta$만큼 회전한 벡터

DOF(degrees of freedom): 상태 표현에 필요한 최소 parameter의 개수

- Euler Angle
	- 3DOF
	- 짐벌 락, 불연속성 등의 문제가 존재함
- Axis-angle
	- 3DOF, 불연속적
	- $\textbf{v}=\theta \hat{\textbf{v}}$ (Rotation Vector)
- Unit quaternions
	- $q = w + ix + iy + kz, w^2 + x^2 + y^2 + z^2 = 1$
- Rotation matrices
	- 곱하면 회전값이 나오는 행렬을 정의하는 방법
	- 각 행은 단위길이를 가지는 벡터이며 서로 수직이다.
	- 역행렬과 전치행렬이 같다. (orthogonal matrix)

DirectX에서는 원래의 기저를 이루는 단위벡터 요소를 통해 Rotation Matrix를 정의한다(축변환).

## Point와 Vector
- 4번째 요소인 $w$가 0이면 Vector, 1이면 Point
