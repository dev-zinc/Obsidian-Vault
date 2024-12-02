# EIGRP의 특징
- [[Distance Vecor RP|DVRP]]와 [[Link-State Routing Protocol|Link-State RP]]의 장점만을 가지므로 "Advanced Distance Vector RP"라고 불리기도 한다.
- Cisco 전용(이었던 것)이며, `224.0.0.10`의 `Multicast Address`를 사용한다.
### Classless RP
-  - `Subnetting`과 `VLSM`을 지원한다.
## Partial Update
-  경로의 변화가 있을 때만 Update를 한다.
- MD5 알고리즘을 통해 서로 간 인증이 가능
- [[Diffusing Update Algorithm|DUAL]]을 통해 (경로 오류 시 등 업데이트 시)최적 경로를 선출한다.
- 첫 연산 시에는 기본 알고리즘 쓰고 이후 업데이트로 유지보수 시에만 [[Diffusing Update Algorithm|DUAL]]이 사용됨.
### EIGRP의 대략적인 작동 절차
1. `Hello Packet`을 통한 `Neighbor` 형성 및 `Neighbor Table` 생성
2. `Update Packet`을 통한 정보 공유 및 `Topology Table` 생성
3. `Topology Table`을 통해 라우팅 경로 계산
## EIGRP Packet의 종류
### 1. Hello Packet
- 인접 라우터와 주고받으며 서로 같은 프로토콜을 사용하는 경우 `neighbor` 관계 형성
- `neighbor`시 `Topology Table`을 공유하고 이를 `DUAL`하여 최적 경로 설정
- 기간마다 다시 보냄
	![alt text](image-2.png)
- 해당 `Hello Interval`의 3배의 시간인 `Hold Time(유지 시간)`동안 주고받지 않으면 `neighbor` 해제
### 2. Update Packet
- 라우팅 정보 보낼 때 사용
- 경로 변화 시만 사용
- `Unicast Address` or `Multicast Address`사용
### 3. Query Packet
- 자신의 `Routing Table`의 경로 장애 시 인접 라우터에 해당 경로의 (대체용) 정보 요청
### 4. Reply Packet
- `Query Packet`에 대한 대답
### 5. Acknowledgement Packet(`ACK`)
- `Update Packet`, `Query Packet`, `Reply Packet`의 수신 확인용
- `ACK`, `Hello`에 대한 대답은 안함
## 그 외 EIGRP에서 사용하는 개념
### Neighbor Table
> `# show ip eigrp neighbor`

3) Routing Table (#show ip route eigrp)

4) FD(Feasible Distance)

5) AD(Advertised Distance)

- 출발지 Next-hop 라우터에서 목적지 네트워크까지 계산한 EIGRP Metric
### Topology Table
> `# show ip eigrp topology`

- 모든 경로 저장 및 최적 경로 선출
- 최적 경로에 장애가 생기면 DUAL로 차선(2nd) 경로 선출
### Feasible Distance(`FD`)
- Destination까지의 $EIGRP\;Metric$`(거리)`
### Advertised Distance(`AD`) or Reported Distance(`RD`)
- Next-hop Router로부터 Destination까지의 $EIGRP\;Metric$
### Successor
- FD가 최소인 경로의 Next-hop Router
### Feasible Successor(`FS`)
- `AD < FD`인 대체 경로의 Next-hop Router
- Successor 장애 시 추가 계산 없이 바로 사용됨
### AS
- ISP에서 전달해주는 번호
- EIGRP 설정에 필요하다.
## EIGRP Topology의 관리
- `FS`를 통해 빠른 수렴이 가능하다.
- `Successor`는 `FD`가 같은 경우 두 개 이상 선출 가능하다.

> [!EIGRP 절차 예시]
> 0. 기본 상태 
> ![img3](image-3.png)
> 1. `D`와 인접한 네트워크 링크에 문제가 생겨 `D`가 `Successor`를 삭제
>  ![img4](image-4.png)
>  2. 인접 `Neighbor`에 `EIGRP Query`, 수신 시 장애 구간을 통하는 경로 삭제
`C`는 `Feasiable Successor`가, E는 `Successor`가 날아간다.
`D`에서 `(a)`로의 `FD`는 `-1`, 즉 도달 불가가 되며 `Active Status`가 된다.
>  ![img5](image-5.png)
>  3. `E`는 재귀적으로 `EIGRP Query` 전송
`C`는 `Reply`
>  ![img6](image-6.png)
>  ![img7](image-7.png)
>  4. 모든 `Query`에 대한 `Reply`가 도착하면 `D`는 새 `Successor`인 `C`, `E`를 선출한다.
>  ![img8](image-8.png)
## EIGRP의 Metric

- 대역폭과 지연시간을 합한 값
### K Value

| K   | Value |                          |
| --- | ----- | ------------------------ |
| K1  | 1     | 송-수신지 사이 가장 작은 bandwidth |
| K2  | 0     | Load                     |
| K3  | 1     | 경로에 따른 누적 Delay          |
| K4  | 0     | 신뢰성                      |
| K5  | 0     | MTU                      |

`K Value`가 모두 동일하며 `AS`가 같은 경우, 인접하다고 판단 가능하다.

> [!예시]
> ![[Pasted image 20241202161246.png]]
> - A-B-C-D : 가장 낮은 대역폭 64kbps, 총 지연 6,000
> - A-E-F-G-D : 가장 낮은 대역폭 256Kbps, 총 지연 8,000
#### 1) A-B-C-D의 EIGRP Metric 계산 
 
> 	$대역폭 = (10^7 / kbps\,단위의\,가장\,낮은\,대역폭 ) * 256$
>	$\qquad\qquad= (10,000,000 / 64 ) * 256 = 40,000,000$
		
> 	$지연 = 모든\;지연 * 256$
>		 $\quad= 6,000 * 256 =1,536,000$

> 	 $Metric = 대역폭 + 지연$ 
> 	 $\qquad\qquad= 40,000,000 + 1,536,000$ 
> 	 $\qquad\qquad= 41,536,000$
#### 2)  A-E-F-G-D의 EIGRP Metric 계산

> 	$대역폭 = (10,000,000 / 256) * 256$ 
> 	$\qquad\qquad= 10,000,000$ 

> 	$지연 = 8,000 * 256$
> 	 $\qquad= 2,048,000$

> 	 $Metric = 10,000,000 + 2,048,000$ 
> 	 $\qquad\qquad= 12,048,000$

- A-B-C-D보다 A-E-F-G-D의 $Metric$이 더 작으므로 A-E-F-G-D 경로를 사용해 EIGRP Packet을 전송한다.