#### Virtual Memory가 매우 커질 때
- HDD를 사용하여 이론상 무한대 크기의 VM 확보
## Demand Paging
- Lazy-Load Time 주소 바인딩
- 이전까지는 모든 필요한 메모리 주소공간을 할당했으나, 이제는 필요할 때 할당
- 실행 시 Execution Time에 필요한 페이지만 업데이트
- Physical Memory 절약
- 또한 LRU를 통해 프레임을 버리고 메모리 확보
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
