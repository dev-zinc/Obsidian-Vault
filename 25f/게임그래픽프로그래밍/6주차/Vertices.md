- Vertex, 정점
[[5. The Rendering Pipeline-3.pdf#page=10&selection=3,1,4,7|5. The Rendering Pipeline-3, page 10]]

|   \   |                Point                 |                 Line                 |               Triangle               |
| :---: | :----------------------------------: | :----------------------------------: | :----------------------------------: |
| List  | ![[Pasted image 20250407122101.png]] | ![[Pasted image 20250407122137.png]] | ![[Pasted image 20250407122153.png]] |
| Strip |                  -                   | ![[Pasted image 20250407122113.png]] | ![[Pasted image 20250407122146.png]] |
- Vertex는 인덱스로서 사용한다.
- 복합체를 표현하기 위해서는 
	1. 삼각형으로 나눈다.
	2. 모든 삼각형의 Vertex index를 저장한다.

```cpp
Vertex v [9] = {v0, v1, v2, v3, v4, v5, v6, v7, v8}; 
UINT indexList[24] = { 
	0, 1, 2, // Triangle 0 
	0, 2, 3, // Triangle 1 
	0, 3, 4, // Triangle 2 
	0, 4, 5, // Triangle 3 
	0, 5, 6, // Triangle 4 
	0, 6, 7, // Triangle 5 
	0, 7, 8, // Triangle 6
	0, 8, 1 // Triangle 7 
};
```
![[Pasted image 20250407122847.png]]