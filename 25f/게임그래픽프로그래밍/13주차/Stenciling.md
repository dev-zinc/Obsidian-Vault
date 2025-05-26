Stencil Test를 통해 Mirror 효과를 구현할 수 있다.
Test를 통과한 경우에만 렌더링하여 거울을 통해 보는 경우만을 선별 가능하다.

Reflection시킨 경우, Normal Vector가 반대가 되므로 
RasterizerState의 FrontCounterClockwise 옵션을 켜주어야 한다.

Stencil Buffer를 통해 Double Blending 또한 방지 가능
Shadow Blending 시, 투영된 Mesh들이 겹치는 경우가 왕왕 발생하는데, 이 경우 그림자가 두 번 블렌딩 된다.
이를 SB를 통해 이미 버퍼에 값이 있는 경우 그리지 않도록 할 수 있다.

