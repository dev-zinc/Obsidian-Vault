1. **컴퓨터 부팅 과정과 I/O 처리 방식:**
    
    - 컴퓨터 전원이 켜진 후 운영체제 커널이 메모리에 로드되어 실행되기까지의 부팅 절차를 BIOS/UEFI 단계부터 커널의 제어권 이전까지 순서대로 설명하십시오. 특히, 부트 로더(예: GRUB)의 역할과 MBR/ESP의 차이점을 포함하여 서술하십시오.

    - CPU가 I/O 장치의 작업 완료를 확인하는 방식인 폴링(Polling)과 인터럽트(Interrupt)를 비교 설명하고, 대용량 데이터 전송 시 인터럽트 방식의 비효율성을 개선하기 위해 등장한 DMA(Direct Memory Access)의 동작 원리와 장점을 설명하십시오.

2. **CPU 스케줄링 알고리즘 비교 분석:**
    
    - FCFS 스케줄링 알고리즘의 작동 방식과 장점(Fairness)을 설명하고, 'Convoy Effect'라는 단점이 발생하는 이유와 그 영향을 서술하십시오.

    - SJF 스케줄링 알고리즘이 FCFS의 Convoy Effect를 어떻게 해결하려고 하는지 설명하고, SJF(및 SRTF)가 실제로 구현 및 사용되기 어려운 이유(CPU-burst time 예측 불가능성)와 발생 가능한 문제점(Starvation)을 논하십시오.

3. **프로세스 상태 전이 및 우선순위 스케줄링 문제 해결:**
    
    - 프로세스가 생성(new)되어 종료(terminated)될 때까지 거칠 수 있는 주요 상태(ready, running, waiting)들을 나열하고, 각 상태 간의 전이(transition)가 어떤 이벤트(예: 스케줄러 디스패치, I/O 요청, 인터럽트 발생 등)에 의해 발생하는지 설명하는 상태 전이 다이어그램(Process State Diagram)의 개념을 서술하십시오.

    - 우선순위(Priority) 스케줄링에서 발생할 수 있는 'Starvation' 문제를 설명하고, 이를 해결하기 위한 기법인 'Aging'의 개념과 작동 방식을 설명하십시오.

4. **CPU 명령어 처리 기법 및 병렬성:**
    
    - RISC와 CISC 명령어 집합 구조(ISA)의 설계 철학 차이를 설명하고, RISC 프로세서에서 명령어 처리 속도를 높이기 위해 사용하는 파이프라이닝(Pipelining)의 기본 단계(Fetch, Decode, Execute, Write Back)와 그 원리를 설명하십시오. 또한, 파이프라이닝의 효율성이 저하될 수 있는 경우(의존성 문제 등)를 언급하십시오.

    - 명령어 수준 병렬성(ILP)을 높이기 위한 하드웨어 기법인 슈퍼스칼라(Superscalar)와 컴파일러 기반 기법인 VLIW(Very Long Instruction Word)의 기본 아이디어를 비교 설명하십시오.

5. **다중 처리기 환경에서의 스케줄링 고려사항:**
    
    - 다중 처리기(Multiple-Processor) 시스템에서 부하 균등(Load Balancing)이 필요한 이유를 설명하고, 이를 위한 두 가지 접근 방식인 Push Migration과 Pull Migration의 개념과 각각의 장단점을 서술하십시오.

    - 프로세서 선호도(Processor Affinity)의 개념을 설명하고, Soft Affinity와 Hard Affinity의 차이점을 설명하며 이것이 왜 다중 처리기 환경에서 성능에 영향을 줄 수 있는지 논하십시오.