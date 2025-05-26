#### Virtual Memory가 매우 커질 때
- HDD를 사용하여 이론상 무한대 크기의 VM 확보
## Demand Paging
- Lazy-Load Time 주소 바인딩
- Page 레벨에서의 swapping
- 이전까지는 모든 필요한 메모리 주소공간을 할당했으나, 이제는 필요할 때 할당
- 실행 시 Execution Time에 필요한 페이지만 업데이트
- Physical Memory 절약
- 또한 LRU를 통해 프레임을 Backing Storage에 내리고 메모리 공간 확보
- 꼭 사용될 메모리만 physical memory에 할당 
#### Demand Paging에서의 Valid-Invalid Bit
- 로드되지 않은 페이지 접근 시
- Page Falut
	- 해당 페이지를 로드 가능한 경우, 즉 사용될 수 있는 경우 physical memory에 업데이트하고 valid로 상태변경
		- Not Allocated - 프로세스에 fault 전송
		- Not in Physical Memory
- Protection Fault
	- 유효하지 않은 접근인 경우, interrupt를 발생시킴 (잘못된 메모리 주소 참조)
#### Page Falut 핸들링
- 실제 로드 가능한 페이지가 디스크에 존재하는 경우
	- MMU가 OS에 Trap을 걸어 PM 할당 및 TLB의 PTE를 valid로 업데이트
#### Copy-on-Write
- write가 
- 메모리를 공유 가능  

#### Page in / out
- Page를 Storage에서 메모리로 로드 / 언로드하는 과정
- 디스크의 특정 영역을 지정해놓고 사용
- Page Swap in / out

#### Page Replacement
- Page Fault 발생 시, OS는 디스크에 내려가있던 페이지를 메모리에 로드
#### Page Replacement Algorithm
- 교체될 가장 적절한 페이지를 선정하는 알고리즘
- Temporal Locality를 거꾸로 생각하여, LRU 기반으로 선정 
#### LRU Clock
- 레퍼런스 비트를 순회
- 1인 경우 0으로 초기화 (Second Chance)
- 0인 경우 victim으로 선정
- approximation이 심해 안씀
#### Not Recently Used
- NRU
- Reference bit, Modify bit 사용
- R
	- Interrupt 시 0으로 초기화
	- Read, Write 시 1로 설정
- W
	- Write시 1로 설정
	- 0으로 초기화되지 않음
![[Pasted image 20250521113048.png]]
- 이를 Enhanced Second Chance라고도 부르며 실제로 사용함
- [ ? ] R, M 중 뭘 먼저 보는지
#### Least Frequently Used
- LFU
- Approx하면 LRU와 같아짐
#### Frame 할당
- Equal Allocation
	- 모든 프로세스에 동일한 양을 할당
- Proportional Allocation
	- 프로세스의 크기에 따라 할당
	- OS가 기본적으로 사용
		- 실제로는 특별한 경우를 위한 우선순위와 함께 사용
- Priority-based Allocation
	- 특정 우선순위 기반 할당
#### Page Replacement
- Local Replacement
	- 프로세스 내에서 교체가 이루어지는 것
- Global Replacement
	- 프로세스 외부와 교체하는 것
#### Frame 수 동적 조정
- page-fault 빈도와 frame 수는 음의 관계
- frame 수 초기 할당 후, page-fault가 일어나지 않으면 프레임을 줄임
- page-fault가 빈번하면 프레임을 늘림
- physical memory의 한계를 고려하여 upper bound와 lower bound를 설정하고 그 사이에서 조정![[Pasted image 20250526105413.png]]

따라서 Page Replacement는 프레임을 모두 사용할 때, Upper Bound에 도달한 경우 일어난다.
#### Thrashing
- 페이지 교체로 인해 프로세스가 과포화되는 것
- 모든 프로세스의 Locality 총합 $>$ Physical Memory 용량![[Pasted image 20250526110035.png]]
#### Working-Set Model
- 시스템 전체 Locality 합
- 프로세스의 Working Set Size $WSS_i=$최근 $\delta$동안 참조된 페이지 수
- $\delta$의 적절한 크기가 주요
## 고려사항
#### Page Size
- Fragmentation
	- Page Size가 작을수록 감소
- Page Table Size
	- Page Size가 작을수록 커짐
- I/O Overhead
	- Page Size가 작을수록 디스크 접근이 많아짐
	-  Page Size가 작을수록 Page Fault 시 디스크 로드 시간이 단축
- Locality
	- Page Size가 커질수록 Locality 활용도는 커짐
	- 그러나 한 번 쓰고 마는 데이터에 대해서는 비효율 발생
	- 적절한 size가 필요
#### TLB Reach
- TLB가 접근 가능한 메모리 용량
- (TLB Size) X (Page Size) 
- Multiple Page Size를 통해 TLB Size 챙길 수 있음
#### Program Structure
- #1 - Spacial Locality 박살
- 1024 * 1024 page faults
	```c
	int A[1024][1024];
	
	for (j = 0; j < 1024; j++) 
	{
		for (i = 0; i < 1024; i++)
		{
			A[i][j] = 0;
		}
	}
	```
- #2 - Spacial Locality 효율적
- 1024 page faults
	```c
	int A[1024][1024];
	
	for (i = 0; i < 1024; j++) 
	{
		for (j = 0; j < 1024; i++)
		{
			A[i][j] = 0;
		}
	}
	```
#### I/O Interlock
- DMA 등이 큰 데이터를 로드하기 위해 할당받은 버퍼가 Page Fault로 인해 Victim으로 선정되는 경우를 방지하기 위해 메모리가 거는 락