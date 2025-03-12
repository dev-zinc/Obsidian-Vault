# Wide Area Network
### Cisco HDLC `(High-Level Data Link Protocol)`
- 시스코 라우터는 HDLC가 기본 캡슐화 방법이며, 점 대 점 연결과 회선 교환에 이용된다.
### PPP `(Point-to-Pont Protocol)`
- 동기 및 비동기 회선을 포함하여 다양한 물리적 인터페이스 표준을 통해 라우터 사이와 호스트 및 네트워크 사이의 연결에 사용되는 표준 프로토콜. 
- 서로 다른 PPP끼리는 연결이 불가능하다 (chap로 구성된 라우터에 pap로 접근 불가능) 
	 #### PAP `(Password Authentication Protocol)`
	- 양방향 인증과정을 통한 간단한 인증 방법 제공
	- 처음 연결하는 과정에서만 인증을 거치기 때문에 CHAP보다 보안에 약함
	- 평문 형태로 전송되므로 해킹 공격에 취약한 단점이 있음
	 #### CHAP `(Challenge Handshake Authentication Protocol)`
	- 3way Handshake 인증과정을 통한 주기적인 인증 실시
	- PAP 인증에 비해서 뛰어난 보안성을 제공
	- MD5 형태로 전송