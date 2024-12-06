# Virtual Private Network
## GRE Tunneling `(Generic Routing Encapsulation)`
- 논리적 인터페이스, 일종의 가상 회선
- 논리적 인터페이스는 자동으로 활성화 됨.
- 실제로는 케이블 등 물리적 인터페이스로 데이터를 주고 받지만, 논리적 인터페이스로 통신하도록 설정
	- Static Routing의 `Administrative Distance`는 1로 더 우선시되므로 이를 통해 설정
![[GRE Tunnel.png]]
## 논리적 Topology와 물리적 Topology