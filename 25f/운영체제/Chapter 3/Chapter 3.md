## Program vs. Process
#### Program
- 디스크에 코드 파일 형태로 저장됨
- 실행되기 위해서는 커널에 의하여 메모리에 로드되어야 함
- 정적 개념
#### Process
- 프로그램의 실행된 인스턴스
- 운영체제가 관리하는 실행 및 스케줄링의 최소 단위
- process ID (PID) 식별자를 가짐
- 동적 개념, 프로그램의 Data Flow의 캡슐화된 버전
### Process Address Space
- 동적 영역 / 정적 영역
- 데이터 영역 / 코드 영역
### Process State Diagram
![[Pasted image 20250331111109.png]]
##### new
- 생성됨
##### ready
- 실행 준비
- running이 Interrupt된 경우
- wating의 I/O 또는 event의 completion
##### running
- 스케줄러가 dispatch한 경우
##### waiting
- I/O 또는 event로 인한 대기
- trap, system call
##### terminated
- 종료
### Process Control Block
![[Pasted image 20250331111429.png]]
- PCB
- 프로세스 중단 시, **현재 레지스터 정보와 PC 정보를 PCB에 백업**한 후, 재개 시 다시 사용할 수 있도록 한다.
- `store state` 작업이 필요한 이유
### Context Switching
방금 중단된 프로세스의 PCB를 백업하고, 실행되어야 할 프로세스의 PCB 정보를 레지스터와 CPU에 올리는 과정을, 즉, 프로세스-커널-프로세스로의 전환 과정을 Context Switching이라 한다.
- 멀티프로그래밍 황경에서 반드시 생길 수 밖에 없는 커널 오버헤드의 원인 중 하나
	- 해당 오버헤드를 줄이기 위해서는 HW의 최적화가 필요하다.
		- 다음 실행될 프로세스를 위한 추가 레지스터 사용
## Scheduler
#### Long-term scheduler
#### Short-term scheduler
- 어떤 프로세스가 다음으로 실행될지 선택
#### Medium-term scheduler (Swapper)
- 메모리 할당 시 부족한 경우, 다른 중단된 프로세스의 남는 자원을 빌려오는 것
### Ready Queue
## Process Operations
#### Creation
- fork()
#### Execution
- exec()
#### Termination
- exit() 
- \_exit()
- abort()
- wait()
#### Cooperating processes
- Inter-Process Communication (IPC)
- 프로세스 간 정보 공유
