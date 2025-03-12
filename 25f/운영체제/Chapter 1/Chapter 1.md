컴퓨터의 정의, 컴퓨터의 3개 분류
## OS
- 하드웨어를 직접 다루지 않고도, SW를 통해 이를 간접적으로 행할 수 있게 하는 HW의 abstract Interface
- 여러 명의 User가 동시에 여러 프로세스를 사용 가능하게 자원 배분의 조절 및 자원 보호
## Controller
*3p - Bus view(Network)*
- 컴퓨터 구조에서 Controller의 존재 의의
- Bus 내에서는 하나의 통신만 가능
- 보통 CPU보다 타 장치의 속도는 매우 느림
- 따라서 임의의 부분을 위임
- 2000년대 이후로 N-S 브릿지 통합됨
- AGP - graphic controller의 일종

*4k 144hz -> 약 3Gbps*

---
N 브릿지에서는 대역폭이 큰 그래픽, 메모리 통신을, S 브릿지에서는 외부와의 연결을 처리한다.
버스 형태 아키텍쳐에서는 병목현상 발생(CPU는 블로킹하므로)
따라서 이 병목을 캐싱, 버퍼링과 보조 HW에 위임하는 방식으로 해결

### 운영체제의 기본 목표
- HW 추상화
	- 예) ADT(자료 타입 추상화) - '명세'를 작성하여 효율성 향상
	  위와 같이, HW 사용의 명세를 작성
- 자원의 공유(multi-process)
	- 시분할(time multiplexing)
	- 공간 분할(space multiplexing)
- 자원의 보호
	- 타 프로세스의 자원 침범 예방
	- 자원 독점 방지
- 프로세스 간의 공정한 자원 분배
- 성능(효율성)
- 개발자(User)에게 좋은 환경을 제공하는 것 

운영체제는 프로세스를 컨트롤하는 소프트웨어이다.
### 자원
- CPU
- 메모리
- I/O 디바이스 등

#### CPU
- Process Unit
	- ALU(Arithmetic Logical Unit): 계산 유닛 (사칙연산, 논리 연산 등)
	- CU(Control Unit): 프로그램의 제어 처리(Control Flow)를 담당
	- MMU(Memory Management Unit): 메모리 관리, 요새는 없음 -> MPU(Protection): 임베디드 
- Register
	- PC(Program Counter): 프로그램 실행에서 다음번 실행할 라인(명령줄)의 메모리 주소
	- IR(Instruction Register): 현재 실행할 라인(명령줄)의 메모리 주소
	- PSW(Program Status Word):  현재 실행 중인 프로세스의 상태(정상, 대기, 예외 등)를 저장
		- Stack Base Pointer: 실행하는 영역(전역/지역 등)에 할당된 메모리의 첫 값 주소
	- General Purpose Registers: 기본적인 연산(사칙연산 등)에 대한 정보를 저장하는 범용 레지스터

##### CPU Architecture
- 폰 노이만 아키텍처
	- CPU - Memory 간 병목 발생
	- Instructions
		- 산술, 논리 연산
		- 제어(Control Flow)
		- 데이터: 
			- Memory: `load, store, move`
			- I/O Devices: `input, output`
- 하버드 아키텍처
	- Code 메모리와 Data 메모리를 분리, 병목을 제거
	- 가끔 임베디드에서 사용 (SRAM, Flash) - XIP (eXecution In Place)
		- 임베디드는 모든 코드가 항상 메모리에 있어야 해서 메모리가 커야 하는데, 메모리의 단가가 높아 비용절감을 위해 하버드 아키텍처와 유사한 구조를 차용
	- 코드와 데이터 중 한쪽만 사용하게 되는 경우 최적화가 어려워짐
	- 설계가 어려움
	- 최악의 경우 메모리는 폰 노이만 구조의 2배가 필요
#### Memory

메모리 구조는 Memory Address Space로 추상화할 수 있다.

```
	[0xFFFFFFFF]
		CSR(C-Startup Routine)	
	Stack - Function Call ( Call 순서와 같음 ) 


	Heap - 동적 할당
	
	Sum, const
	Code 
	[0x00000000]
```
---
# * [?]
컴퓨터 부팅 시:
1. CPU의 상태 확인, 비정상인 경우 부팅 불가능
2. 이후 고정된 위치로 포인터를 옮겨(Program Counter 이동) 바이오스(현 UEFI)를 실행
3. 컴퓨터의 동작을 위해 필수적인 인터페이스와 메모리의 상태를 확인
	- POST(Power On Self-Test)
	- 이 테스트를 통해 하드웨어의 검증 종료
4. 디스크에서 (멀티OS의 경우, 선택된) 운영체제의 시작 포인터 위치를 읽어오기 위해 부트 디바이스 (MBR)실행, 이후 부트로더(LILO, GRUB) 실행, 이후 부트로더는 메모리에 OS를 올림
	- MBR - BIOS
	- ESP - UEFI
		- LILO의 경우, 리눅스 부트로더로서 운영체제의 설치 위치가 바뀌면 항상 위치를 업데이트해줘야 하는 반면, GRUB은 논리적으로 실행되므로 편하다.

### CPU 
- __Instruction Set Architecture__ (ISA)
	- 명령어의 집합
	- 여러 기본 명령을 조합하여 n번에 처리할 것을 1번에 처리 가능하게 만든(HW적으로) 명령어와 기본 명령어의 집합
	- 그러다 보니 복잡해진 ISA를 CISC(Complex)라 한다.
	- 이를 다시 필요한 명령만 가지고 구성한 것이 RSIC(Reduced)이다.
		- RSIC: ARM
		- CISC: Inter, AMD
- __Pipelining__
	- 기본적인 RSIC의 연산과정은 다음과 같다.
		- Fetch: 프로그램 카운터의 다음 실행될 명령을 IR에 등록하는 과정
		- Decode: IR에 저장된 명령을 전기적 명령으로 변환하는 과정
		- Execute: CPU 실행
		- Write Back: 계산 결과 반환
	- 각 연산 사이클끼리 서로 의존관계가 없는 경우, 동시에 이루어질 수 있다.
	```
	1 F D E W
	2   F D E W
	3     F D E W
	4       F D E W
	--------------> t
	```
	- 분기 처리 등, 의존관계가 있는 경우 효율적이지 않을 수 있다.
	- 또한, 각 절차의 수행 시간이 오래 걸리는 경우에도 비효율적일 수 있다.
	- 따라서 RISC는 CISC의 4배가 아닌 약 2.1배의 성능 향상을 가진다.
- __Instruction-Level Parallelism__(ILP)
	- 독립적인 명령의 경우, HW레벨에서 명령을 병렬처리
	- Superscalar, VLIW
		- __Multicore Architecture:__ n-Core
		- __Symmetric Multiprocessing Architecture__: CPU 여러 개 사용
			- __NUMA__: CPU 1개당 메모리 1개
		- __Clustered System Architecture__: 컴퓨터를 묶어 사용
			- __Distributed System__
### I/O Operation
- 기본적으로 IO장치는 느리다. 따라서 CPU가 외부장치를 처리하는 경우 병목현상이 발생하기 매우 쉽다. 
- 따라서, IO장치에는 그를 위한 IO Controller가 필요하다.
##### I/O Method
- Interrupt
	- CPU가 I/O 작업이 진행되고 있는지, 끝났는지 확인하는 데는 두 가지 방법이 있다.
		- Polling: 주기적으로 작업상태를 체크하는 기법
		- Interrupt: I/O Controller가 Interrupt Signal을 전송하면 CPU가 즉시 작업을 중단하고 I/O 처리를 이어 하는 것 