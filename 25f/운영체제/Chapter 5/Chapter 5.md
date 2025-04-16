### Burst 
- CPU burst
	- CPU 연산에 대한 waiting
- I/O burst
	- I/O에 대한 waiting
- CPU-bound Process
	- CPU-burst의 비중이 높은 프로세스
- I/O-bound Process
	- I/O burst의 비중이 높은 프로세스
## Dispatcher
#### Dispatch
- User로의 컨텍스트 스위칭
#### Dispatch Latency
- 한 프로세스를 중단하고, PCB에 상태를 저장하고 다른 프로세스의 상태를 꺼내 재개하기까지 걸리는 시간 

넓은 의미에서 Scheduling에 포함된다.
## Preemptive
선점.
- 스케줄러가 작업에 interrupt를 걸고 force context switch가 가능하다. 
## Non-preemptive
- job이 끝나기까지 무조건 기다린다.
---
## Scheduling Criteria
#### CPU utilization
- 최대화
- keep the CPU as busy as possible
- CPU는 항상 최고 부하로 돌아가야 함
#### Throughput
- 최대화
- \# of processes that complete their execution per time unit
#### Turnaround time
- 최소화
- amount of time to execute a particular process
#### Waiting time 
- 최소화
- amount of time a process has been waiting in the ready queue
#### Response time 
- 최소화
- amount of time it takes from when a request was submitted until the first response is produced, not output (for time-sharing environment)
## Scheduling Goals
#### Interactive systems 
- **Response time:** minimize average time spent on ready queue 
- **Waiting time**: minimize average time spent on wait queue ü **Proportionality**: meet users’ expectations
#### Real-time systems 
- **Meeting deadlines**: avoid losing data 
- **Predictability**: avoid quality degradation in multimedia systems
## Scheduling Non-goals
#### Starvation
- 프로세스가 자원을 스케줄링받지 못하고 계속(영원히!) Ready Queue에 남는 것
## Scheduling Algorithms
#### FCFS
- First Come First Serve
- Starvation이 발생하지 않는 아주 Fair한 알고리즘
- Non-preemtive
- 후열 작업의 Waiting Time이 매우 길어짐
	- *Convoy Effect*
- 이렇듯 성능이 들쭉날쭉한 것이 단점
#### SJF
- Shortest Job First
- Convoy Effect를 방지하기 위해 등장
- [[Optimal]] Minimun Average Wating time을 가짐
###### 단점
- 긴 프로세스가 대기상태일 때, 계속해서 짧은 프로세스가 들어오는 경우 Starvation이 발생 가능
- 분기처리 상 CPU-bursting Time을 예측할 수 없음
	- 구현 불가능
#### SRTF
- Shortest Remaining Time First
- Preemtive한 SJF
- 위와 같이, 예측 불가능성 존재.
	- 예측 알고리즘 또한 오차가 심해 사용불가
#### Priority
- 프로세스의 임의의 가중치(우선순위)를 따름
- Preemtive, Non-preemtive 모두 구현에 따라 가능
- 결국에는 무엇을 가중치로 하든 대부분 계산이 불가능함 (Starvation)
###### 해결책
- Aging
	- 시간에 따라 가중치를 증가시켜 주는 것
- 이 경우, 우선순위 기반의 알고리즘 상의 Starvation은 해결 가능하다.
- 그러나 여전히 Real-Time하고 Interactive한 응답에 어려움이 존재
#### Round-robin
- RR
- SJF보다 평균 Context Switching수는 더 크지만 응답성이 더 좋음
- time quantum, $q$
	- $q \rightarrow\infty$: FIFO
	- $q$ $is$ $small$: 큰 오버헤드
- $q$가 크면 RR의 의미가 없어지고, 작으면 스위칭 오버헤드가 너무 커진다.
- 일반적으로 $q \in [10ms, 100ms]$
- Context Switching Time $<$ 10$\micro$s
### Algorithm Combinations
- 여러 알고리즘을 혼합하여 사용
#### Multi-Level Queue
- Queue를 여러 개의 레벨로 쪼갬
	- Foreground(Interactive, I/O) Level
		- RR
	- Background(batch) Level
		- FCFS
#### Multi-Level Feedback Queue 
- 짧은 $q$에 대하여, 
	- $q$를 다 쓰지 않고 waiting하는 경우: I/O bound일 확률 높음
	- 다 쓰고도 연산이 남은 경우: CPU bound일 확률 높음
- 이후 더 긴 $q$를 가지는 Queue Class에 할당해보며 판단을 마치면 FCFS Queue에 대기시킴
	- 예측이 아님 경험 기반이므로 가볍고 빠르다.
- 약 170여개의 Priority Level 을 3-4개의 클래스로 나누어 작동
## Multiple-Processor Scheduling
#### Load Balancing
- Push migration
	- 연산이 몰린 코어가 다른 코어로 작업을 주는 것
	- 부하가 있는 코어가 로드밸런싱까지 담당하므로 오버헤드 존재
- Pull migration
	- 연산이 없는 코어다 다른 코어의 작업을 가져오는 것
	- 다른 코어의 상황을 알지 못해 발생하는 오버헤드 존재
- 두 가지 모두 장단점이 존재하며 효율성을 위해서는 H/W지원이 필요
#### Core Ready Queue
- Common Ready Queue
	- 커널 오버헤드가 상대적 적음
- Per-core Run Queues
	- 각 코어당 할당된 캐시 등의 자원 효율을 극대화
#### Processor Affinity
- Common Ready Queue 사용 시, 위의 캐싱 효율 등을 고려하기 위하여 사용되고 있던 코어에 프로세스를 할당하는 것
- Soft Affinity
	- 최선의 할당 시행
- Hard Affinity
	- 
## Real-Time Scheduling
- 주기
- Bursting TIme
#### Static
- Rate-Monotonic algorithm
- 설계 시 시간을 측정하여 측정값을 박아넣음
- 모든 스케줄링 케이스를 점검하여 데드라인을 지킬 수 있는지 없는테 테스트함
#### Dynamic
- 안씀
- 임베디드 환경에서의 알고리즘 계산 자체가 매우 큰 오버헤드

## Linux Scheduling
- MLFQ
- 가변적 우선순위
	- 트리 구조로 관리
## Windows Scheduling
- MLFQ
- 고정된 우선순위를 가지고 관리
## Solaris Scheduling
- MLFQ

### Algorithm Evaluation
- Modeling
	- Deterministic modeling
	- Queueing models
- Simulation
	- Cf) Emulation (Enviornment + Simulation)
- Implementation