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

---

- 2000년대 이후로 N-S 브릿지 통합됨
- AGP - graphic controller의 일종

*4k 144hz -> 약 3Gbps*

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

Memory Address Space 
```
	[0xFFFFFFFF]
		CSR(C-Startup Routine)	
	Stack - Function Call ( Call 순서와 같음 ) 


	Heap - 동적 할당
	
	Sum, const
	Code 
	[0x00000000]
```

