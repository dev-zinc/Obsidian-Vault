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