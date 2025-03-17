```cpp
while (1) {
	if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			break; // 추가
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
```
