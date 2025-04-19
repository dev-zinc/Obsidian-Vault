## Program vs. Process
#### Program
- 디스크에 코드 파일 형태로 저장됨
- 실행되기 위해서는 커널에 의하여 메모리에 로드되어야 함
- 정적 개념
#### Process
- 프로그램의 실행된 인스턴스
- 운영체제가 관리하는 실행, 스케줄링, 자원 관리의 최소 단위
- process ID (PID) 식별자를 가짐
- 동적 개념
- 프로그램 Data Flow의 캡슐화
### Process Address Space
- 동적 영역 / 정적 영역
- 데이터 영역 / 코드 영역
### Process State Diagram
![[Pasted image 20250331111109.png]]
##### new
- 생성됨
##### ready
- 자원을 받아올 수 있는 상태. 자원을 받으면 running으로 이동
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
- PCB에 레지스터 백업이 있어야 Context Switching이 가능해진다.
- `store state` 작업이 필요한 이유
### Context Switching
방금 중단된 프로세스의 PCB를 백업하고, 실행되어야 할 프로세스의 PCB 정보를 레지스터와 CPU에 올리는 과정을, 즉, 프로세스-프로세스 또는 프로세스-커널 간의 전환 과정을 Context Switching이라 한다.
- 멀티프로그래밍 황경에서 반드시 생길 수 밖에 없는 커널 오버헤드 중 하나
	- 해당 오버헤드를 줄이기 위해서는 HW의 최적화가 필요하다.
		- 다음 실행될 프로세스를 위한 추가 레지스터 사용
## Scheduler
#### Long-term scheduler
#### Short-term scheduler
- 어떤 프로세스가 다음으로 실행될지 선택
- ctx sw 발생
#### Medium-term scheduler (Swapper)
- 메모리 할당 시 부족한 경우, 다른 중단된 프로세스의 남는 자원을 빌려오는 것
### Ready Queue
- 자료구조의 Queue가 아님
여러 개의 대기열을 두고, 종류에 따라 사용한다.
- IO Device
- 시분할된 프로세스
## Process Operations
#### Creation
- fork()
	- 어떤 프로세스의 clone 작업
		- 1. PCB 생성 및 초기화
		- 2. 원본 PCB 내용 deep copy
		- 2-1. 이 과정에서 파일 포인터 등은 shallow copy 진행
			- => 자원 공유 가능
		- 3. 만들어진 PCB를 ready queue에 place
		- 4. 부모(Caller)에게는 만들어진 PID를, 자식에게는 0을 반환
	- fork시 실행 순서, 자식/부모 구분과정
		- ==**fork 실행 시점의 state를 전부 복사하여 그 상태의, 즉 fork() system call에 대한 대기 상태인 자식을 생성**==
			- ==이후 커널은 두 프로세스 모두에 리턴 수행==
		- 통신 구현 시, 하나의 커넥션에 대하여 커넥션을 유지한 채로 요청 핸들링이 가능하다.
		- 부모는 핸들링 후 exit
		- 자식은 핸들링하지 않고 대기
	- 위 과정이 병렬로 이루어지기 때문이다.
		```c
		while (1) {
			int sock = accept();
			if ((pid = fork()) == 0) {
				/* Handle client request */
			} else {
				/* Close socket */
			}
		}
		```
#### Execution
- `int exec (char *prog, char *argv[])`
	- 다른 프로그램 코드를 실행
	- 현재 프로세스를 중단하고, program counter를 업데이트한다.
		- 현재 프로세스에 `wait()`을 건다.
		```c
		while (1) {
			char *cmd = read_command();
			int pid;
			
			if ((pid = fork()) == 0) {
				/* Manipulate stdin/stdout/stderr
				for pipes and redirections, etc. */
				exec(cmd);
				// if failed
				panic(“exec failed!”);
			} else {
				wait (pid);
			}
		}
		```
- Windows에서는 `CreateProces`를 사용하는데, 이는 fork와 exec을 합쳐놓은 느낌이다.
	- Thread 이후 개발된 OS의 특성
##### C start-up Routine
- exec 시 실행되며, 마지막 명령은 실행할 프로그램의 main 함수를 call하는 것
- C 프로세스가 실행되기 위한 제반작업 수행
#### Termination
- exit() 
	- 정상종료
	- exit <exitCode\>
	- 종료를 위한 제반작업을 수행한다.
		- 마지막 명령은 \_exit
- \_exit()
	- 커널 레벨의 exit
	- 반드시 종료한다.
- abort()
	- abnormal termination
	- 커널에서 비정상적인 종료 시 terminal signal을 전송
- wait()
	- 종료 시 자식 프로세스 종료까지 대기
	- 부모 프로세스가 wait 없이 자식 프로세스를 실행한 경우 자식 프로세스는 zombie가 된다
	- 이때 부모 프로세스가 종료되면 자식 프로세스는 orphan이 된다.
		- 이를 보완하기 위하여 `pid=1`인 `init`프로세스가 대리부모 역할을 한다.
		- 모든 zombie, orphan 프로세스에 대한 wait을 수행한다.
#### Cooperating processes
- Inter-Process Communication (IPC)
- 프로세스 간 정보 공유
##### Message Queue
- 커널이 관리
- System Call 형태로 사용 가능
- 오버헤드
##### Shared Memory
- 자유도 높지만 개발해야 함
- Notice가 어려움

- Circular Queue를 이용한 Producer-Consumer 구조
	- sync issue 존재

[ ? ]둘이 같이 쓰면 ?

##### Socket
- TCP/IP를 이용한 메세징

##### RPC
- Remote Procedure Call

