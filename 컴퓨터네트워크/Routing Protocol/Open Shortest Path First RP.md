# OSPF의 특성
- 가장 많이 사용되는, "표준" 개방형 프로토콜
- [[Link-State Routing Protocol|Link-State RP]]를 사용한다.
- 업데이트 내용이 없어도 30분 간격으로 `Link-State Refresh`를 한다.
- `224.0.0.5`와 `224.0.0.6`의 `Multicast Address` 사용
- `pid` 존재
- 설정 복잡함
## OSPF의 절차
1. Neighbor 맺기
2. LSA 공유 -> LSDB에 저장
3. LSA를 SPF or Dijikjstra로 최적 경로 Routing Table에 저장
4. 주기적으로 `Hello Packet` 교환하며 정상 동작을 확인
5. 네트워크의 상태가 변하면 위의 과정 반복해서 Routing table 생성
## OSPF Packet의 종류
### Hello Packet
- `OSPF`가 설정된 이웃 라우터와 인접 관계를 맺기 위해 사용
### DBD(`Database Description`)
- 링크 상태 정보에 대한 `DB`이며, `OSPF` 라우터들 간의 `DB` 동기화를 검사하기 위해 사용

### LSR(`Link-State Request`)
- DBD를 받은 후, 자신에게 없는 경로가 있을 경우 이 경로에 대한 상세한 링크 상태 정보를 요청할 때 사용

### LSU(`Link-State Update`)
- LSR에 대한 응답
- 이웃 라우터와 경로 비용 등 상태 정보를 LSA(`Link-State Advertisement`)의 형태로 전송
### LSAck
- 상기의 다른 패킷 유형에 대한 수신 확인
## OSPF의 계층 구조
![alt text](image.png)

- 무조건 `Area 0`를 거쳐 통신해야 한다. `Backborn Area`라고도 부른다.
-  전체 토폴로지를 Area 0으로 설정해도 상관은 없다.
## OSFP의 비용 계산
![alt text](image-9.png)
### Loopback Address(1.1.1.1)
- Loopback Interface에 할당됨
- 라우터의 Interface는 물리적(실제), 논리적(가상)으로 나뉜다.
가상 인터페이스의 대표적인 예시가 Loopback이다. 이는 외부 접속 시 일회성 ip 등으로 쓰인다.

`ip [AD/Metric]`