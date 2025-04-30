## Deadlock
- 서로가 사용 중인 공유자원에 대해 waiting하여 교착상태에 빠진 상태
#### Deadlock의 필요조건
- 상호배제
- Hold and Wait
- 비선점(No preemtion)
- 순환대기

위 4가지 조건이 모두 충족되는 경우 [[Non-deterministic]]하게 Deadlock이 발생한다.

앞선 철학자 문제의 해결책에서는 Hold and Wait을 제거(no holding). 
#### Deadlock 핸들링
- 예방
	- 꼭 필요한 상황에서만 공유자원 hold
- 회피
	- 발생할 요청을 처리하지 않음
	- 커널 오버헤드가 큼
- 탐지 및 회복
	- 발생 시 처리하는 법
	- 모니터링 비용이 발생
- 무시
	- The ostrich algorithm
	- Deadlock을 처리하지 않음
	- 개발자에게 핸들링 위임
		- 커널의 책임은 동기화 문제를 해결하는 것까지
