## CIA Triad
- 기, 무, 가의 약어
- Confidentiality
	- 기밀성
		- 권한이 없는 경우 데이터를 읽을 수 없게 하는 것
		- 즉, 비정상적인 접근(Read)을 막는 것
- Integrity
	- 무결성
		- 권한이 있어야 데이터를 변조 가능하게 하는 것
		- 즉, 비정상적인 접근(Write)을 막는 것
- Availability
	- 가용성
		- 권한 있는 유저가 필요할 때 빠르게 접근 가능한 경우
		- 서버가 공격당해 관리자가 서비스에 접근이 어려운 경우 가용성이 깨졌다고 생각할 수 있음

그러나 완벽한 보안 시스템은 존재하지 않는다.
- 따라서 지속적인 관제가 필수불가결함
#### 관련 용어
- Vulnerability
	- CIA에 결함이 있는 것
- Threat
	- 취약점 악용의 가능성
	- 취약점이 존재하는 '상황' 그 자체
- Attack
	- 해커의 공격 행위
- Adversary
	- 공격 대상이 될 수 있는 시스템의 한 부분
- Countermeasure
	- 공격에 대응하는 것

Nonrepudiation - 부인 방지
- 시스템에 로그로 남아 전송자 등이 전송을 부인 불가한 것

#### 크래커의 기본 시작점
- 해당 사이트에 대한 최대한의 정보수집
- Port Scanner를 통한 러닝 상태인 서비스의 포트 정보 수집
	- 약한 보안서비스 탐색
- 임의의 계정 탈취
- Root 권한 탈취
- 백도어 등을 통한 이후 접근 숏컷 뚫어놓기

#### 물리적 보안
- HW
- BIOS
- Session
	- 물리적으로 몰래 타인의 컴퓨터를 통해 작업하는 것 등

#### 계정 보안
#### 파일 시스템 보안
#### 네트워크 보안
- 보안 프로토콜 사용
	- SSH, SFTP, HTTPS, SSL 지원, IPSec 등 
- TCP Wrapper
- 방화벽
- Intrusion Detection / Prevention System
	- 방화벽의 발전된 버전
	- IDS, IPS

