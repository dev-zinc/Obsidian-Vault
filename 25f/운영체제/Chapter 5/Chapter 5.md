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
### Starvation
- 프로세스가 자원을 스케줄링받지 못하고 계속(영원히!) Ready Queue에 남는 것

## Scheduling Algorithms
#### FCFS
- First Come First Serve
- NO Starvation
- Non-preemtive
- 후열 작업의 Waiting Time이 매우 길어짐
	- *Convoy Effect*
#### SJF
- Shortest Job First
- Convoy Effect를 방지하기 위해 등장
- [[Optimal]] Minimun Average Wating time을 가짐
###### 단점
- 긴 프로세스가 대기상태일 때, 계속해서 짧은 프로세스가 들어오는 경우 Starvation이 발생 가능
- 분기처리 상 Bursting Time을 예측할 수 없음
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
- SJF보다 평균 회전율은 높지만 응답성이 더 좋음
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
	- Foreground(Interactive)
		- RR
	- Background(batch)
		- FCFS
- 
#### Multi-Level Feedback Queue 
- MLFQ