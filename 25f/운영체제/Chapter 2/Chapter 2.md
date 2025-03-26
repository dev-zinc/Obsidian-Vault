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
	.c -> Compiler { Pre-Processor -> Translator }
		-> .obj -> Linker { 라이브러리, 코드 파일 통합 }
		-> .out (.exe)
- Linking
	- Static
		- 실행 파일 내에 라이브러리를 내포함. 
		- 파일을 한 번에 올리고, dll을 모두 사용하지 않고 일부분만 사용하는 경우 사용
	- Dynamic
		- `.dll` (Windows)
		- `.sa`, `.so`
		- 위치를 가지고 라이브러리의 코드 실행 시 라이브러리 위치의 코드를 실행
		-  여러 프로세서에서 공유하여 사용 가능하므로 효율적이다.