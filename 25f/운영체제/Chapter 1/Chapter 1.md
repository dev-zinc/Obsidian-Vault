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
###### Process Unit
- ALU(Arithmetic Logical Unit): 계산 유닛 (사칙연산, 논리 연산 등)
- CU(Control Unit): 프로그램의 제어 처리(Control Flow)를 담당
- MMU(Memory Management Unit): 메모리 관리, 요새는 없음 -> MPU(Protection): 임베디드 
###### Register
- PC(Program Counter): 프로그램 실행에서 다음번 실행할 라인(명령줄)의 메모리 주소
- IR(Instruction Register): 현재 실행할 라인(명령줄)의 메모리 주소
- PSW(Program Status Word):  현재 실행 중인 프로세스의 상태(정상, 대기, 예외 등)를 저장
	- Stack Base Pointer: 실행하는 영역(전역/지역 등)에 할당된 메모리의 첫 값 주소
- General Purpose Registers: 기본적인 연산(사칙연산 등)에 대한 정보를 저장하는 범용 레지스터
#### CPU Architecture
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
### 컴퓨터 부팅 절차
1. CPU가 스스로 초기화하고 이상이 없는지 확인
2.  Program Counter를 움직여 `0xfffffff0` 위치의 instruction 실행
3. instruction이 BIOS코드의 첫 주소로 이동
4. 컴퓨터의 동작을 위해 필수적인 인터페이스와 메모리의 상태를 확인
	- POST(Power On Self-Test)
		- CPU, 메모리, 기타 IO 디바이스의 검사 및 초기화 진행
5. 디스크에서 boot device 검색
6. 해당 boot device의 MBR 또는 ESP를 메모리에 로드 후 실행
	- 여기에는 부트로더(LILO 또는 GRUP)의 첫 코드가 존재
7. 이후 바이오스는 부트로더에 제어권 이전
8. 실행된 부트 디바이스가 부트로더를 메모리에 로드 및 실행
9. 부트로더가 압축된 커널을 메모리에 로드
10. 커널은 스스로 압축을 풀고 압축해제된 커널에게 제어권 이전

### CPU Instruction
##### __Instruction Set Architecture__ (ISA)
- 명령어의 집합
- 여러 기본 명령을 조합하여 n번에 처리할 것을 1번에 처리 가능하게 만든(HW적으로) 명령어와 기본 명령어의 집합
- 그러다 보니 복잡해진 ISA를 CISC(Complex)라 한다.
- 이를 다시 필요한 명령만 가지고 구성한 것이 RSIC(Reduced)이다.
	- RSIC: ARM
	- CISC: Inter, AMD
##### __Pipelining__
- 기본적인 RSIC의 연산과정(사이클)은 다음과 같다.
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
##### __Instruction-Level Parallelism__(ILP)
- 독립적인 명령의 경우, HW레벨에서 명령을 병렬처리
	- Superscalar - 인텔, 두 연산이 의존관계가 없으면 HW레벨에서 병렬수행
	- VLIW: - Very Long Instruction Word
		- 컴파일러가 독립적인 명령을 찾아 하나의 VLIW로 묶음
- __Multicore Architecture:__ n-Core
- __Symmetric Multiprocessing Architecture__: 한 Memory가 CPU 여러 개 사용, Bus가 1개 => 병목이 생기긴함
	- __NUMA__: CPU 1개당 메모리 1개
- __Clustered System Architecture__: 컴퓨터를 묶어 사용
	- __Distributed System__
	- Storage Area Network (SAN)
### I/O Operation
- 기본적으로 IO장치는 느리다. 따라서 CPU가 외부장치를 처리하는 경우 병목현상이 발생하기 매우 쉽다. 
- 따라서, IO장치에는 그를 위한 IO Controller가 필요하다.
#### I/O Method
- Interrupt
	- CPU가 I/O 작업이 진행되고 있는지, 끝났는지 확인하는 데는 두 가지 방법이 있다.
		- Polling: 주기적으로 작업상태를 체크하는 기법
		- Interrupt: I/O Controller가 Interrupt Signal을 전송하면 CPU가 즉시 작업을 중단하고 I/O 처리를 이어 하는 것
			- Interrupt Signal에는 task의 성공, 실패 여부와 결과가 담겨 있다.
		- DMA(Direct Memory Access)
			- 인터럽트도 결국에는 병목이 걸리게 된다. 이를 해결하기 위해 나온 방법.
			- 데이터가 큰 경우, DMA controller가 메모리에 다이렉트로 버퍼의 형태로 데이터를 전송하게 된다. 
			- __이 과정에서 메모리에 엑세스할 수 있는 권한을 CPU에게 위임받는다.__
			- 이후, 전송이 완료되었을 때 disk controller가 한 번 인터럽트를 CPU에 쏜다.

---
#### I/O mode
##### Synchronous/Blocking
##### Asynchronous/Non-Blocking

## I/O State

#### Interrupt
- async
- HW device에 의하여 생김
#### Trap
- sync
- 어플리케이션 레벨에서의 System Call(OS Interface의 사용)
#### Falut(Exception)
- sync
- CPU 연산 도중 예외발생 시 스스로 Interrupt를 걸고 예외를 반환 (HW 레벨)
- 커널 코드의 메모리 주소에 Write를 거는 경우 등 (App 레벨)

**어플리케이션 레벨인지 하드웨어 레벨인지를 구분하는 것이 중요하다.**

---
### ROM
- read-only Memory
- 휘발성이 없음
- 한번 쓰면 다시 덮어쓸 수 없음
### RAM
- Random Access Memory
- 액세스 시간이 O(1)
- 전기가 끊기면 뒤짐
#### SRAM
- Static RAM
- 재료가 좋아 데이터의 변형이 일어나지 않는다
- 따라서 Register와 Cache는 SRAM을 사용한다.
## Cache

> [!quote] Temporal Locality
> *가장 최근에 사용된 데이터는 다시 사용될 확률이 가장 높다.*
> *또한, 그 근처에 있는 데이터가 그 다음으로 다시 사용될 확률이 가장 높다.*
*c.f Spacial Locality*

캐싱 정책은 위 법칙을 따른다.
- Cache Hit : 찾는 데이터가 캐시에 존재하는 경우
- Cache Cold: 없어서 메모리에 액세스해야하는 경우
이렇게 아래 레이어(더 느리고 더 비싼!)에 대한 접근을 최소화하는 것이 캐싱의 의의이다.
#### Cache Coherency의 관리
###### Write-Through
- 캐싱된 데이터가 변하는 경우 아래 레이어에 데이터를 전파하는 것
- 느리지만 정합성을 지킬 수 있다.
###### Write-Back
- 메모리가 한산할 때마다 Sync를 맞추는 방법
- 빠르지만 정합성이 망가질 가능성이 있다.
## DRAM
- Dynamic RAM
- 소자가 상대적으로 저렴하여 전기신호가 약해져 왜곡이 생긴다.
- 이를 해결하기 위하여 일정 시간이 지나면 전기신호를 증폭시켜준다.
- 해당 시간 동안에는 메모리 접근이 불가능하여 DRAM이 더 저렴하다.
- Main Memory에서는 DRAM을 사용한다.
## HDD
- 여러 장의 platter로 구성되며 platter 끝의 head 부분에 arm이 움직여 접촉하여 데이터를 읽는다.
- 여러 장의 platter를 cylinder라고 한다.
- 읽을 수 있는 데이터의 최소 단위 sector, 섹터가 한 장의 platter를 채우면 track, 플래터 묶음이 실린더

*※20p 그림 참고!*
## SSD
- solid state disk
- 고장이 잘 안남
#### NAND Flash Memory
- 블록 단위로 구성됨
- SSD 내의 Flash Controller에 의해 조작된다.
- 한 블록에 여러 데이터를 쓸 수 있다. 
- 블록 내 데이터에 덮어씌우지 않고 해당 데이터를 읽기 금지 시킨다.
- 그렇게 블록 내 모든 데이터가 읽기 금지가 되면 비로소 해당 블록을 clear한다.
- ware-leveling
	- 데이터를 최대한 고르게 블록에 할당시켜 블록을 고르게 aging시키는 것
##### FTL
- HDD와 유사하게 SSD를 사용 가능하게 해 주는 레이어
---
### System Call

*c.f) Function Call*

- 애플리케이션 레벨에서 커널을 호출하는 것
- System call 시 커널 모드로 전환한 후(trap to Kernal Mode, save app state) Trap Handler가 Vector Table에서 해당하는 Call을 찾아 이를 실행한다. 이후 Call이 종료되면 User mode로 전환하여 결과를 반환한다.(restore app state)
	- 오버헤드가 있음에도 듀얼 모드 구조를 사용하는 이유는 HW 보호를 위해서이다.
	- Kernal Interface의 사용을 강제하는 것.
- System call 시 Trap에 걸린다는 표현을 사용
### HW Protection

#### CPU Protection
- Timer
	- 한 프로세스의 독점에 대하여, 일정 시간을 정해놓고 해당 시간 이상 자원을 사용하는 경우 스스로 인터럽트를 거는 것.
	- 이후 커널은 해당 인터럽트를 핸들링한다.
	- 스케쥴러
#### Memory Protection
- 한계 이상의 메모리를 할당하는 것 방지
- 다른 프로세스가 점유하는 영역을 침범하는 것 방지
	- Segment Violation in Linux
#### I/O Protection
 - Dual mode
	 - 오직 Kernal에서만 HW 접근이 가능
	 - 권한 필요
- OS가 Kernal로 작동하는 경우:
	- Bootstrapping
	- System Call
	- Interrupt
## 컴퓨터의 역사

### 1세대
- Aniac
### 2세대
- 트랜지스터, Mainframe
- Batch System
	- 한 번에 하나의 프로그램만 실행 가능
	- MS-DOS
- 이때는 Resident Monitor의 형태로 OS가 존재했다.
### 3세대
- IC 집적회로
- 컴퓨터 아키텍쳐에 대한 정의가 거의 정립된 시점
- Multiprogramming System
	- 한 시스템 하에서 여러 프로그램이 돌아가는 것처럼 실행 가능한 구조
	- CPU 자원의 효율적 사용을 위하여 
	- 하나의 HW를 여러 프로세스가 사용하기 시작하여 관리가 복잡해짐
		- 이를 관리하기 위한 소프트웨어가 **운영체제**
	- ((메모리 관점))
- Time-Sharing System
	- 자원의 시분할
	- ((CPU 관점))
### 4세대 (80s ~ 현재)
- LSI, VLSI
	- SOC 형태의 HW
- CPU 연산의 위임
	- 각종 컨트롤러
- PC, 데스크탑 컴퓨터의 도입
	- (이전까지는 하나의 컴퓨터에 여러 유저가 접속하여 사용했었음)
- GUI, 웹, 분산환경 등 여러 기술 발전
## 컴퓨팅 환경
### Traditional
#### Mainframe System
- Batch System
- Multiprogramming System
- Time-Sharing System
#### Desktop System
### Mobile
#### Hand-held System
- 한정된 메모리
- 느린 프로세서
- 작은 화면
### 그 외
#### Real-Time Embedded System
- Hard Real-time
	- 비행기 운행/관제 시스템 등
- Soft Real-time
	- 실시간 동영상 스트리밍 등

**기한을 지키지 못했을 경우의 이슈의 중대함**에 따라 Hard System과 Soft System을 나눌 수 있다.

Task가 동작하는 데 걸리는 시간을 보장하는 시스템
- **최소한 정해진 시간 안에는 결과를 내야 하는 경우**에 사용
- 대부분 임베디드 환경에서 동작하므로 Real-Time Embedded System이라 부른다.
### P2P
- Napster, VoIP 등등
- client 간 직접 통신
### Cloud
#### IaaS
- Infrastructure as a Service
- HW 자원만을 제공
- AWS 등
### PaaS
- Platform as a Service
- 소프트웨어 스펙을 지원
	- HW, OS, MiddleWare 레벨
- AWS의 각종 상품
#### SaaS
- Software as a Service
- 원격 자원을 소프트웨어 형태로 제공하는 서비스
- Google Drive 등
### 가상화
- VMM(VM Manager)
	- VMM이 여러 VM의 자원 관리
	- 한 VM 당 한 사용자로 간주
- Hypervisor
- JVM
	- 어떤 OS이든 Java를 실행 가능하게 해줌
- Distributed Computing
	- Hadoop
---
### UNIX
- MACH -(steve jobs)-> Next Step -> macOS
- Linux는 오픈소스 모임의 이름이었음
#### 현행 UNIX 서버 OS
- Sun Solaris -> 서버 시장의 60% 차지
- HP HP-UX 
- IBM AIX
- Caldera (SCO) Unixware
- Compaq (Digital) Tru64

이후 UNIX계열 제품끼리 호환이 되지 않아 System Call에 대한 표준을 정의함
- POSIX
#### Embedded System
- VxWorks
	- Hard Real-Time System