thread cooperation

여러 프로세스 또는 스레드가 공유자원에 동시에 접근하는 경우 Race Condition을 생성

이러한 문제가 발생 가능한 Code Section에 대하여 Critical Section이라 하며, 해당 문제를 Synchronization Problem이라 한다.
## Synchronization 관리 조건
#### Mutual Exclusion
- 타 프로세스의 critical section 실행 중에는 공유자원에 접근하지 않는 것
#### Progress
- 다른 크리티컬 섹션이 작동하는 프로세스가 없는 경우, 크리티컬 섹션 진입 시 바로 공유자원을 사용할 수 있어야 함
#### Bounded Waiting
- 공유 자원에 대한 Starvation이 존재해서는 안 됨

---
#### Locks
```c 
lock();
unlock();

//...

struct lock { int held = 0; } 

void lock(struct lock *l) { 
	// busy-waits
	while (l->held) 
		; 
	l->held = 1; 
} 

void unlock(struct lock *l) { 
	l->held = 0; 
}
```
#### Spinlocks
- lock이 공유자원이 되어 문제 발생 (lock에 대한 race condition)
- Busy-waitng 발생
	- 이름의 유래(spinning in loop)
	- 내용 없는 반복문으로 wait을 구현하는 것
###### Solutions
- __SW__
	- Algorithm 1, 2, 3
		- for 2 Processes
	- Bakery Algorithm
		- for  # (≥ 2) Processes
- __HW__
	- Atomic Instructions
		- Test-and-set
			- lock이 하나의 instruction으로써 존재
		- Compare-and-swap
			- __단점__
				- busy-waiting의 큰 CPU 비용
- Disable Interrupts
	- Context Switching 금지
	- 트랜잭션 단위 동안의 아토믹함 유지
		- __단점__
			- 사용자가 쓰면 큰일남
			- 커널에서만 사용
			- 매우 잘 사용해야 함
			- I/O 등의 크리티컬한 인터럽트를 받을 수 없음
	
싱글코어에서는 DI를, 멀티코에서는 개선된 스핀 락을 사용한다.
DI는 시스템 전역에 락을 걸며 스핀 락은 해당 자원에만 락을 건다.
#### Semaphore
> ![[Pasted image 20250421112605.png]]

- 깃발; 교차로를 오직 한 기차만 지날 수 있는 것에서 유래
- 티켓이 존재
- wait
- signal
	- Critical Section Sync
	- 함수적 의존
	- 사용자 수의 제한 
#### Mutex
- Binary Semaphore
- 티켓 수가 2인 세마포어

- __장점__
	- busy waiting이 없다.
#### Deadlock
- 서로가 상대의 자원에 대해 대기하는 경우, 교착상태에 빠지는 것
### Monitors
- JVM
- 공유 자원에 대한 명세 및 인터페이스를 정의
- 설계 차원에서 불필요한 대기가 발생할 수 있음
- 하나의 모니터 클래스에 정의된 메소드에 대하여, 동시에 한 개의 메소드만 실행 가능
##### Condition Variables
- 불필요한 대기를 해소
- wait
- signal 
- 히스토리가 없는 세마포어 (boolean flag)