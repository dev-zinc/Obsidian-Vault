## Fence
- GPU와 CPU간 동시성을 지키기 위한 개념
- CPU는 GPU의 현재 Queue 연산 종료시까지 대기
- `UINT_64` 타입 
- 일종의 뮤텍스.

예제에서는 `FlushCommandQueue`함수에서 CommandQueue에서 펜스에 대한 Signal 이후 `SetEventOnCompletion`를 통해 완료 시 작업을 등록하여 사용하고 있다.
## Barrier
- GPU 내 자원이 completed되지 않은 상태에서 사용되는 것을 뜻하는 Resource Hazard를 예방하기 위해 사용
#### Transition
- 자원에 상태를 부여함
- 이러한 자원을 사용하기 위해 GPU는 반드시 상태의 Transition을 통해야 한다.
#### Helper Structure
- C로 시작하는 구조체는 Helper Struct로써 다양한 생성자와 팩토리 메소드를 가진다.
- CD3DX12_RESOURCE_BARRIER를 통하여 D3D12_RESOURCE_BARRIER를 쉽게 생성할 수 있다.