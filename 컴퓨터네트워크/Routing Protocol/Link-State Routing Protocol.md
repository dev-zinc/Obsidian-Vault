## RIP 이후 알고리즘의 공통점

1. `Hello Message`를 주고받으며 서로 동일한 RP인지 확인한다.

이후 `neighbor 관계`를 맺는다.

2. `neighbor`끼리는 `Topology table`을 공유한다.

3. 이후 다익스트라 or SPF 알고리즘을 통해 최적의 경로를 탐색한다.
## Link State RP

직접 연결된 네트워크 링크 정보를 연결된 네트워크의 라우터에게 공유한다.

이 정보는 `Link State Packet(LSP)`에 담겨 공유되며,

이는 네트워크 링크에 대한 `Cost`정보를 갖는다.

![alt text](image-1.png)
이렇게 가중 그래프 형태를 갖는다.

`bandwidth`가 크면 `cost`가 작다.
## Enhanced Interior Gateway RP(`EIGRP`)

- DVRP와 Link State의 장점만을 가지므로 `Advanced Distance Vector RP`라고 불리기도 한다.

- Cisco 전용(이었던 것)이며, `224.0.0.10`의 `Multicast Address`를 사용한다.

- `Classless RP` - `Subnetting`과 `VLSM`을 지원한다.

- `Partial Update` - 경로의 변화가 있을 때만 Update를 한다.

- `MD5` 알고리즘을 통해 서로 간 인증이 필요(가능)하며,

`DUAL(Diffusing Update ALgorithm)`을 통해 (경로 오류 시 등 업데이트 시)최적 경로를 선출한다.

- 첫 연산 시에는 기본 알고리즘 쓰고 이후 업데이트로 유지보수 시에만 DUAL이 사용됨.

  

대략적인 작동 절차는 다음과 같다.

  

1. `Hello Packet`을 통한 `Neighbor` 형성 및 `Neighbor Table` 생성

2. `Update Packet`을 통한 정보 공유 및 `Topology Table` 생성

3. `Topology Table`을 통해 라우팅 경로 계산

  

### DUAL

  

어떤 구간의 통신이 불가능해지는 경우, `DUAL`은 다음과 같이 작동한다.

  

1. 장애가 발생한 네트워크의 라우터가 정보 공유

2. 정보를 받은 라우터는 해당 메시지에 대한 `ACK` 전송

3. 장애가 발생한 네트워크의 라우터는 이에 대하여 `EIGRP Query` 전송

4. `Query` 수신 후 `ACK`, 이후 `EIGRP Reply`를 전송

5. `Reply` 수신 후 `ACK`

  

```

장애가 발생한 구간에

도달 가능한지 여부

EIGRP Query <------> EIGRP Reply

```

  

### EIGRP Packets

  

- ### Hello Packet

- 인접 라우터와 주고받으며 서로 같은 프로토콜을 사용하는 경우 `neighbor` 관계 형성

- `neighbor`시 `Topology Table`을 공유하고 이를 `DUAL`하여 최적 경로 설정

- 기간마다 다시 보냄

  

![alt text](image-2.png)

- 해당 `Hello Interval`의 3배의 시간인 `Hold Time(유지 시간)`동안 주고받지 않으면

`neighbor` 해제

  

- ### Update Packet

  

- 라우팅 정보 보낼 때 사용

- 경로 변화 시만 사용

- `Unicast Address` or `Multicast Address`사용

  

- ### Query Packet

  

- 자신의 `Routing Table`의 경로 장애 시 인접 라우터에 해당 경로의 (대체용) 정보 요청

  

- ### Reply Packet

  

- `Query Packet`에 대한 대답

  

- ### Acknowledgement Packet(`ACK`)

  

- `Update Packet`, `Query Packet`, `Reply Packet`의 수신 확인용

- `ACK`, `Hello`에 대한 대답은 안함

  

### Terms

- ### Neighbor Table

  

> `# show ip eigrp neighbor`

  

3) Routing Table (#show ip route eigrp)

4) FD(Feasible Distance)

-

5) AD(Advertised Distance)

- 출발지 Next-hop 라우터에서 목적지 네트워크까지 계산한 EIGRP Metric

- ### Topology Table

  

> `# show ip eigrp topology`

  

- 모든 경로 저장 및 최적 경로 선출

- 최적 경로에 장애가 생기면 DUAL로 차선(2nd) 경로 선출

  

- ### Routing Table

  

> `# show ip route eigrp`

  

- 최적 경로가 등록되는 테이블

- 이를 참조하여 라우팅

  

- ### Feasible Distance(`FD`)

- Destination까지의 `EIGRP Metric(거리)`

  

- ### Advertised Distance(`AD`) or Reported Distance(`RD`)

  

- Next-hop Router로부터 Destination까지의 `EIGRP Metric`

  

- ### Successor

  

- FD가 최소인 경로의 Next-hop Router

  

- ### Feasible Successor(`FS`)

  

- `AD < FD`인 대체 경로의 Next-hop Router

- Successor 장애 시 추가 계산 없이 바로 사용됨

  

### EIGRP Topology의 관리

  

`FS`를 통해 빠른 수렴이 가능하다.

  

`Successor`는 `FD`가 같은 경우 두 개 이상 선출 가능하다.

  

<details>

<summary>EIGRP 예시 절차</summary>

  

![alt text](image-3.png)

  

`D`와 인접한 네트워크 링크에 문제가 생겨 `D`가 `Successor`를 삭제

![alt text](image-4.png)

  

인접 `Neighbor`에 `EIGRP Query`, 수신 시 장애 구간을 통하는 경로 삭제

  

`C`는 `FeasiableSuccessor`가, E는 `Successor`가 날아간다.

  

`D`에서 `(a)`로의 `FD`는 `-1`, 즉 도달 불가가 되며 `Active Status`가 된다.

![alt text](image-5.png)

  

`E`는 재귀적으로 `EIGRP Query` 전송

  

`C`는 `Reply`

  

![alt text](image-6.png)

  

![alt text](image-7.png)

  

모든 `Query`에 대한 `Reply`가 도착하면 `D`는 새 `Successor`인 `C`, `E`를 선출한다.

  

![alt text](image-8.png)

</details>

  

### K Value

|K|Value|Mean|

|---|---|---|

|K1|1|송-수신지 사이 가장 작은 bandwidth|

|K2|0|Load|

|K3|1|경로에 따른 누적 Delay|

|K4|0|신뢰성|

|K5|0|MTU|

  

K Value가 모두 동일하며 AS가 같은 경우, 인접하다고 판단 가능하다.

  

- #### AS

ISP에서 전달해주는 번호

  

### Metric

  

Metric = (경로 상의 가장 낮은 대역폭) + (누적 지연)

  
  
  

## OSPF(`Open Shortest Path First`) RP

  

- 가장 많이 사용되는, "표준" 개방형 프로토콜

- `Link-State`를 사용한다.

- 업데이트 내용이 없어도 30분 간격으로 `Link-State Refresh`를 한다.

- `224.0.0.5`와 `224.0.0.6`의 `Multicast Address` 사용

- `pid` 존재

- 설정 복잡함

### `OSPF`의 절차

  

1. Neighbor 맺기

2. LSA 공유 -> LSDB에 저장

3. LSA를 SPF or Dijikjstra로 최적 경로 Routing Table에 저장

4. 주기적으로 Hello ㅖacket 교환하며 정상 동작을 확인

5. 네트워크의 상태가 변하면 위의 과정 반복해서 Routing table 생성

  

### Packets

  

- #### Hello Packet

- `OSPF`가 설정된 이웃 라우터와 인접 관계를 맺기 위해 사용

- #### DBD(`Database Description`)

- 링크 상태 정보에 대한 `DB`이며, `OSPF` 라우터들 간의

`DB` 동기화를 검사하기 위해 사용

- #### LSR(`Link-State Request`)

- DBD를 받은 후, 자신에게 없는 경로가 있을 경우 이 경로

에 대한 상세한 링크 상태 정보를 요청할 때 사용

- #### LSU(`Link-State Update`)

- LSR에 대한 응답

- 이웃 라우터와 경로 비용 등 상태 정보를

LSA(`Link-State Advertisement`)의 형태로 전송

- #### LSAck

- 상기의 다른 패킷 유형에 대한 수신 확인

  

### OSPF의 계층 구조

  

![alt text](image.png)

  

무조건 `Area 0`를 거쳐 통신해야 한다. `Backborn Area`라고도 부른다.

  

근데 전체 토폴로지를 Area 0으로 설정해도 상관은 없다.

  

### OSFP의 비용

  

![alt text](image-9.png)

  

### Loopback Address(1.1.1.1)

- Loopback Interface에 할당됨

  

라우터의 Interface는 물리적(실제), 논리적(가상)으로 나뉜다.

가상 인터페이스의 대표적인 예시가 Loopback이다. 이는 외부 접속 시 일회성 ip 등으로 쓰인다.

  

`ip [AD/Metric]ss`