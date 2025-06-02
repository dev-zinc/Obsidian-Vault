## I/O
#### Direct I/O
- CPU에서 바로 데이터 접근
- 상대적으로 빠름
- instruction이 분리되어 있음
	- MEMR / MEMW
	- IOR / IOW
#### Memory-Mapped I/O
- 메모리 일정 영역을 I/O와 매핑시키고 메모리에 Read/Write 수행
- CPU 아키텍처의 복잡도 낮음
- 상대적으로 느림
- Instruction이 통합되어 있음
	- MEMR / MEMW

...

#### Spooling
- 느린 I/O Device가 메모리에서 데이터를 받지 않고 파일 형태로 큰 데이터를 통째로 접근하게 하는 것
- 하나의 느린 Device가 시스템 전체를 느리게 하는 것을 방지하기 위함