# Link-State RP`(상태-링크 라우팅 프로토콜)`의 특성
- [[다익스트라 알고리즘]] 또는 [[최단 경로 우선 알고리즘]] 알고리즘을 사용하여 라우팅
## Link-State RP의 작동 순서
1. Link State Packet`(LSP)` 생성
	- 직접 연결된 네트워크 링크 정보와 그 `Cost` 정보 적재
2. 같은 네트워크의 모든 라우터에게 LSP 발송
3. LSP 수신 시, 각 경로의 Cost를 기준으로 최단 경로 생성
## Link-State Cost

![alt text](image-1.png)
- 각 경로는 Cost를 가중치로 하는 가중 그래프 형태를 갖는다.
- `bandwidth`가 크면 `cost`가 작다.