## Process fork의 단점
#### 1. Heavyness
- 메모리 주소 공간(코드, 데이터)의 복사
- PCB는 무거운 객체(task_struct)
#### 2. Costly
- 높은 IPC 비용(OS를 거치므로)
	- Context Switching 오버헤드
## Thread
![[Pasted image 20250407111127.png]]
#### Concept
- 나눠지는 분기의 상태정보만을 기억
- 하나의 프로세스 내에서
	- 메모리 공간(Code, Data)
	- 자원
- 은 복사하지 않고 Thread State만을 복사하여 실행
#### Thread State
- PC
- SP(Stack Pointer)
- register

> Thread는 Function 단위로 나누어진다. 
> 이때, Function 수행을 위해 Stack 영역이 필요하다. 
> 따라서 각 Thread에 Stack 영역, 즉 각각의 Stack Pointer가 할당된다.
## Concurrency
### Parallel Programming
- 여러 Core를 사용하여 정말 동시에 작업을 수행하는 것
	- Pthreads (POSIX threads)
	- OpenMP (Open Multi-Processing)
	- Open MPI (Message Passing Interface) 
	- SIMD (Single Instruction Multiple Data) 
	- GPGPU (General Purpose computing on GPUs) 
	- **CUDA (Compute Unified Device Architecture)**
	- OpenCL (Open Computing Language)
##### Data Parallelism
- 한 Task 내 작업을 쪼개서 행함
##### Task Parallelism
- 여러 Task를 동시에 행함
## User-level Thread
- User Threads
	- Pthreads(POSIX)
	- C-thread(Mach)
	- threads(Solaris)
- Thread 개념 정립 시기, 모놀리식 OS에 스레드 패치가 어려워 User-level Library로 개발해놓음
	- Thread Table이 User에 있어 Kernal Shedulling이 망가지는 경우 왕왕 발생
		- 커널이 Thread에 대한 정보를 모르는 경우 System Call을 호출하는 작업만 wait되며 다른 CPU-bursting한 작업은 스케줄링되지 않을 수 있음
	- => 결국 커널에 통합
### Kernal-level Thread
- Thread의 생성 및 관리가 System Call에 의존함
	- Windows 95/98/NT/2000 
	- Solaris 
	- Tru64 UNIX
	- BeOS 
	- Linux

#Control_Flow_다변화 #Register_값_다변화

`하나의 Control Flow = 하나의 Thread`

## Multithreading Models
#### Many-to-One
- User-level Thread
#### One-to-One
- Kernal-level Thread
#### Many-to-Many
#### Two-level
- MtM + OtO
## Fork in Multithreading Enviorment
- fork가 모든 스레드를 복사, 즉 프로세스 전체를 copy해야 하는가?
- 아니면 해당 스레드만을 복사해야 하는가?
	- 구현 환경에 따라 매우 다른 결과가 나타남
	- fork 이전에 thread 생성을 하지 않는 것이 관습

