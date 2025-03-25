- Domain Name System
- *네임서버*
## Hosts FIle
- DNS 이전에 쓰임
- 현재도 많이 쓰임
- IP를 캐싱해두고 사용
- 바뀌지 않는 solid한 IP에 대하여 하드코딩해놓고 사용

> `/etc/hosts`
> `windows\system32\drivers\etc\hosts`

보통 비어있으며, __DNS보다 우선순위가 높다__.
분산화된 환경에서 작동한다.
## 작동 원리
- IP를 이름으로 매핑
- FQDN (Fully Qualified Domain Name): 완성된 주소
> `<Root>.<국가/조직 특성>.~~`
> `예) www.youtube.com` 
## DNS 계층 구조
![[{0F5105F1-D557-4146-93E7-02A3824AF16E}.png]]

## DNS 서버 등록법
- 리눅스
	- `/etc/resolv.conf`에 DNS 네임서버 입력
	- DNS 서버의 도메인 이름을 알 수 없으므로 IP주소를 사용
- 윈도우
	- IP주소 설정 시 DNS도 설정가능

## DNS 이름 해석 순서
0. hosts 파일 탐색
1. 로컬 DNS 서버
2. 루트 DNS 서버
3. 마지막 도메인 `(.com, .kr, .net 등)`을 관리하는 서버
4. 두 번째 도메인까지를 담당하는 서버 `(.co.kr, .ko.kr, .ac.kr, ~~.com)`

맨날 하면 렉걸리니까 캐싱해둠

> `ipconfig /displaydns` 로 캐싱된 주소 확인
> `ipconfig /flushdns`로 캐시 삭제

## DNS 레코드의 종류

#### A 레코드
- 도메인에 대해 IP주소를 부여함

