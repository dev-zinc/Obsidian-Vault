단어의 유래는 외교의 통역
## 프로토콜의 3요소
### Syntax
데이터의 구조 또는 형식
### Semantics
통신에 있어서 흐름 제어, 예외 핸들링과 같이 정의된 규칙
### Timing
언제, 얼마나 빠르게 정보가 오가는지
## 프로토콜의 기능
### Addressing
이기종 간 상대의 주소를 무조건 하나의 엔티티로 정의하는 것
### Sequence Control
(없는 경우도 있음: UDP)
연결 지향적 통신에서, 데이터의 순서를 보장하는 것 (TCP)
### Fragmentation & Reassembly
큰 데이터를 전달하는 경우, 잘게 쪼개어 전달하는 것
이후 수신 측에서 이를 재조립
### Encapsulation
제어를 위해 데이터에 정보를 더하는 것
### Connection Control, Flow Control
연결의 발행, 종료의 제어 및 데이터의 속도 제어

이 외 다수가 있다.