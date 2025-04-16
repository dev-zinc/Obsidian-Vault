256bytes의 최소 크기를 가진다.
256의 배수를 또한 할당 크기로 설정 가능하다.
```cpp
static UINT CalcConstantBufferByteSize(UINT byteSize) {
	return (byteSize + 255) & ~255; 
}
```

- WVP matrix 등 연산 시 필요한 값을 저장하는 데 사용한다.