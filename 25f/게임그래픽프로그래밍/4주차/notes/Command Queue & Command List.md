- 스레드 간 경합이 일어나는 경우나 명령 사이에 의존성이 있는 경우, 병렬연산이 불가능한 경우가 있다. 
- 이 경우, 해당 연산장치의 자료구조에 따라 동기적으로 처리하게 된다.
## Command Queue
- GPU
## Command List
- DirectX API를 통해 리스트에 저장된 명령을 Queue에 push
## Command Allocator
- 실제 명령이 저장되는 공간
- 리스트는 여기에 있는 명령에 대한 record를 가진다.
