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
## OSI 7 Layer
### TCP/IP 4 Layer
TCP/IP에서 사용되는 압축된 버전
### Physical Layer
- Cable(HW)
- Connector
+ 무선 통신(RF)
	+ UART Signal Communication(RF계의 ICMP)
+ 시리얼 통신

L1의 보안 이슈로 인하여 HW 분해를 통해 데이터 수집이 필요한 경우가 존재

- 장치
	- 리피터
		- 약한 신호를 다시 강하게 보냄(마크랑 똑같음)
	- 허브
		- 스위치의 초기버전
		- 허브는 유니캐스트도 멀티로 때리지만 스위치는 신호를 한 포트에만 전달한다.
#### Modulation
RF통신에서, 데이터를 전파로 변환하는 것
그 역을 Demodulation이라 한다.

기본 전파인 Baseband Signal에 데이터를 중첩하여 전송한다.

- AM(Amplitude Modulation)
	- 진폭의 조절
	- 진폭의 높낮이에 정보를 담는다.
- FM(Frequency Modulation)
	- 진동수의 조절
	- 진동수의 변화에 정보를 담는다.
- PM(Phase Modulation)
	- 위상의 조절
	- 올라갔다가 다시 내려가지 않거나 하는 식으로 주기성을 파괴하여 정보를 전달한다.
### Data Link Layer
- MAC Address
- Ethernet
	- 이더넷 패킷의 길이 범위는 64바이트~1518바이트이다.