### User Interface Service
- CLI
	- Shell
		- Kernal을 감싸는 껍데기, 추상화의 의미를 담음
	- bash (born-again shell)
- GUI
### System Programs
- 애플리케이션을 실행하고 개발하는 데 필요한 도구 제공
	- 컴파일러
	- 파일
	- 언어
### 컴파일 과정
- .c -> Compiler { Pre-Processor -> Translator }
	-> .obj -> Linker { 라이브러리, 코드 파일 통합 }
	-> .out (.exe)
- Linking
	- Static
		- 실행 파일 내에 라이브러리를 내포함. 
		- 파일을 한 번에 올리고, dll을 모두 사용하지 않고 일부분만 사용하는 경우 사용
	- Dynamic
		- `.dll` (Windows)
		- `.sa`, `.so` (Linux, Shared의 의미)
		- 위치를 가지고 라이브러리의 코드 실행 시 라이브러리 위치의 코드를 실행
		-  여러 프로세서에서 공유하여 사용 가능하므로 효율적이다.
---
## System Call Service
#### System Call Vector Table

| System Call | Id  |
| ----------- | --- |
| Open        | 0   |
| Read        | 1   |
| Write       | 2   |
| Close       | 3   |
위 4개 Call은 가장 자주 쓰이는 것들이다.
#### System Call Parameter
- System Call의 Input Parameter는 function call stack이 아닌 무조건 레지스터에 push된다.
- 오버헤드 경감
## OS Structure
절차 지향적 구조는 HW조작에 있어 유리한 면이 있음
#### Monolithic Kernal
- 절차-지향적 프로그래밍
	- 높은 결합도, 어려운 유지보수
	- -> Layered Approach
#### Micro Kernal
- Layered Approach의 부분적 적용 사례
- message로 인한 커널 오버헤드 문제가 매우 큼
	- 못씀
	- Modular Approach
#### Modular Approach
- 코드는 마이크로틱, 컴파일된 결과는 모놀리식
- Loadable Kernel Module (LKM)
	- 현재 가장 많이 쓰이는 방식
### Hybrid Approach
- Mac OS X
	- Micro인 MACH 위에 BSD를 올려서 씀
	- HW와 SW를 함께 개발하기 때문에 나타나는 특성
- iOS
- Android
	- Linux 위에 가상 머신과 각종 서비스, Android Framwork를 올려 사용



