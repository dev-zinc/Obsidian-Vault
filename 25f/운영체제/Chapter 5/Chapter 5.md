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