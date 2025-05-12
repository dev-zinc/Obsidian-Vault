## 메모리 관리
#### 목표
- 추상화를 통한 개발자 편의성 기능 제공
- 여러 프로세스에 적은 오버헤드로 효율적 분배
- 프로세스 당 독립적인 자원 할당
	- 자원의 격리 및 보호
#### 문제점
- 다수의 프로세스를 지원해야 함
- 매우 큰 메모리 용량을 요구하는 프로세스 존재
- 자원 보호와 동시에 자원의 공유가 이루어져야 함
- 프로세스마다의 Segment 지원
- 효율적 성능(오버헤드 경감)
#### 해결책
- Virtual Memory (VM)
	- 논리적(virtual) 메모리 주소와 물리적 메모리 주소의 분리
## 메모리 바인딩
- 데이터가 Logical Memory Address를 얻는 과정 
#### Compile Time
- 컴파일 시점에 할당될 주소 결정
- instruction 자체에서 지정한 주소를 사용
###### 문제점
- 예) 같은 프로세스가 실행 중일 시 충돌
- 또한 컴파일 타임에 검사할 요소가 많음
- 임베디드 시스템 등에서 사용
	- 런타임 중 주소 연산 등을 생략 가능
- 그러나 멀티프로그래밍 환경에서 부적합
#### Load Time
- 메모리에 올라갈 때 주소 결정
- Base Address를 임의로 지정하고, 실제로 로드될 때 Base Address만큼 더해서 데이터를 찾음![[Pasted image 20250507104829.png]]
- 예) 
	- 98000에 저장하는 instruction
	- 100000에 로드
	- 198000에서 찾음
###### 문제점
- Load Time에 주소 연산을 전부 하여 시간이 길어짐
- 또한 불필요한(사용하지 않는) 코드까지 전부 로드하므로 비효율적
- 거의 사용하지 않음
#### Execution Time
- Load Time과 기본적으로 동일하나 Access될 데이터에 대해서만 주소 연산을 실행
- 실제로 사용
###### 문제점
- Load Time에 비해 주소 연산 시간만큼 느림
###### 해결책
- 해당 주소 연산만을 위한 [[Chapter 9#MMU|MMU]] 사용
#### MMU
- Memory Management Unit
- Virtual Memory를 Physical Memory로 매핑하는 HW Device
- User Program에서는 Logical Memory를 다룸
#### Contiguous Allocation
- Logical Memory는 연속적
- CPU는 Logical Address만 다룸
- Logical Address를 MMU에 전달
	- Limit Register가 할당된 최대 메모리 (TOP) 이내에 있는지 검사
	- 범위 밖인 경우 CPU에 Interrupt 전송
- Relocation Register가 Physical Address를 계산
	- `Physical address = logical address + relocation register`
	- Base Address 사용
#### Multiple-partition allocation
- __Hole__
#### Hole 핸들링
- First-fit
	- Hole 탐색 도중 할당 가능한 경우 바로 할당
- Best-fit
	- 모든 할당 가능한 Hole 중 가장 작은 곳에 할당
- Worst-fit
	- 가장 큰 곳에 할당

First-fit과 Best-fit이 그나마 성능이 낫다.
그러나 이는 여전히 근본적 해결책이 되지 않는다.
## Fragmentation
#### External Fragmentation
- 남은 메모리는 할당하는 데 충분하나 연속적인 공간이 없는 것
#### Internal Fragmentation
- [[Chapter 9#Paging|Page]] 내부에서 발생하는 Fragmentation
## External Fragmentation의 해결책
#### Compaction
- 메모리 조각 모음
- 현재 할당된 메모리를 섞어 하나의 큰 블록으로 몰아넣음
	- I/O, 즉 메모리 접근이 너무 많아 오버헤드 매우 큼
#### Paging
- 일정한 크기로 메모리 블록을 생성
- Logical Memory-> Page, Physical Memory -> Frame
- Page와 Frame은 일대일대응 관계
- Page Mapping (Table)을 관리하는 것이 매우 중요해짐
- Page 내부에서는 [[Chapter 9#Execution Time|Execution Time Binding]] 사용
##### Paging에서의 주소변환
- Address Translation
- `(page_number, offset) |--mapping--> (frame_number, offset)`
##### Page Table
- OS가 관리하는 `Page - Frame` 주소 간의 매핑테이블
- 한 프로세스 당 하나의 Page Table을 사용
##### 문제점
- [[Chapter 9#External Fragmentation|External Fragmentation]]은 없지만 [[Chapter 9#Internal Fragmentation|Internal Fragmentation]]은 발생 가능
- 내부 파편화 정도는 그냥 감수하고 사용
#### Paging 예제
- Logical address: 32 bits
- Physical address: 20 bits
- Page size: 4KB
	- -> 4096bytes, 위치정보를 표현하는 데 12bits ($4096=2^{12}$)
- -> offset: 12bits, page numbers: 20bits
- -> 가능한 Page 개수: $2^{20}$개

예) 
```json
Logical Address(32): '00004AFE'
Page Table: [
	'27', 
	'D0', 
	'31', 
	'FE', 
	'46', 
	'A4'
]
=> Physical Address(20): '46AFE'
```
> [!EXAMPLE] Logical Memory의 크기
> Page Table을 통해 실제 메모리보다 월등히 많은 공간을 가진 가상 메모리를 정의하는 것이 가능하다.
> => `Logical Memory 공간은 Page Table에서 정의할 수 있는 만큼 커질 수 있다.`
#### Free Frame List
- 빈 Frame을 관리하는 리스트
## Page Table의 구현
- Page Table은 메인 메모리에 저장됨
- 이 경우, 어떤 데이터 or 명령 접근 시에도 2번의 메모리 접근이 일어나고 이는 오버헤드로 이어짐
#### Associative Memory
- 기존 메모리는 병렬 탐색이 불가능하나, AM은 병렬적으로 찾는 것이 가능
	- 따라서 캐싱된 데이터에 한해 O(1)에 수렴하는 탐색시간을 가짐
#### TLB
- Translation Look-aside Buffer 
- MMU가 관리하는 Page Table 캐시
- HW로 구현되어 있음
- 99% 이상의 Cache hit율을 보임
	- TLB miss 시, 캐시 업데이트만 진행하고 다시 캐시에서 찾게 함
	- 회로적 복잡도를 낮추기 위함
- 
#cold_cache #hot_cache
#### TLB miss 핸들링
#### TLB 관리
- TLB가 꽉 찬 경우
	- Temporal Locality의 역인 LRU를 사용하여 캐시를 덮어씌움
	- Least Recently Used
#### Effective Access Time
$EAT = (1+\epsilon)\alpha+(2+\epsilon)(1-\alpha)$
 $= 2+\epsilon-\alpha$

## Valid-Invalid Bit
- Main Memory Protection을 위해 Page table에서 사용
## Page Table Entries
- PTEs![[Pasted image 20250512112907.png]]
- V
	- Valid bit
	- 해당 PTE가 사용 가능한 상태인지 표기
- R
	- Reference bit
	- 해당 페이지가 접근된 적 있는지 표기
- M
	- Modify bit
	- 해당 페이지가 쓰인 적 있는지 표기
- Prot
	- Protection bits
	- 해당 페이지에 허용된 연산을 표기 (RWE)
- FN
	- Frame number
## Page Table 구조
#### Page Table 관리
- 프로세스가 요구하는 데 비해 과도하게 큰 Page Table 크기
#### Hierarchical paging 
- 무손실 압축
- Two-level paging
[ ? ] Page Table이 왜 무조건 4MB를 고정으로 가지는지
#### Hashed page table
- 손실이 발생 가능한 압축
- 해싱한 페이지 넘버를 링크드리스트 형태로 관리
- 그렇다보니 읽기성능이 현저히 줄어듬
#### Inverted page table