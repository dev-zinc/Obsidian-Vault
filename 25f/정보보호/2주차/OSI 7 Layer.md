패킷은 레이어가 내려갈수록 커진다.

	Byte Header
		ㄴMAC Header
			ㄴIP Header
				ㄴTCP Header
					ㄴ...
	[            Data            ]
# TCP/IP 4 Layer
TCP/IP에서 사용되는 압축된 버전
## Physical Layer
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
### Modulation
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
## Data Link Layer
- MAC Address
- LAN 환경
- Ethernet
	- 이더넷 패킷의 길이 범위는 64바이트~1518바이트이다.
#### CRC
패킷 오류를 확인하기 위한 Hash Checksum

- 장치
	- 브릿지
		- LAN끼리 연결
	- 스위치
		- MAC 주소에 대한 처리를 수행

## Network Layer
- IP Address
- WAN 범위의 통신
![[Pasted image 20250312153156.png]]

호스트의 수에 따라 다른 클래스의 대역을 사용할 수 있다.

#### IPv6
- 128bits(16Bytes)

### ARP
- Address Resolution Protocol
	- IP 주소를 기반으로 하여 MAC 주소를 찾는 프로토콜
	- LAN 내에서 사용
#### ARP Spoofing
- LAN 내부의 보안 문제
- 스위치는 ARP를 브로드캐스팅하므로, IP주소를 속이면 원래 목적지로 가야 할 패킷을 도청할 수 있다.
- 안전하지 않은 LAN 환경에서는 반드시 따로 보안절차를 거쳐야 한다.

#### ICMP
- ping
여러 메시지가 존재

TTL(Time to Live)를 매우 짧게 하여 라우터에 보냄으로써 tracert와 같은 애플리케이션 구현 가능
### Routing
#### Static Routing
정적 라우팅. 보안용으로 사용 가능
#### Dynamic Routing
동적 라우팅
## Transport Layer
- Port
- 