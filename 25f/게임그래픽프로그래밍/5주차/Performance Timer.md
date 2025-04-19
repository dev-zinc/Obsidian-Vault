HW와 렌더링 등 환경적인 요소를 고려하여 timer가 필요하다.
- `QueryPerformanceCounter`
- `QueryPerformanceFrequency`
- $mSecondsPerCount = \frac{1}{countsPerSec}$
- $valueInSecs = valueInCounts * mSecondsPerCount$
멀티스레딩 환경에서는 타이머를 별도 스레드에서 동작하게 하는 (메인 어플리케이션 스레드의 스위칭을 막는) `SetThreadAffinityMask`를 사용할 수 있다.

교재에는 `GameTimer` 클래스가 선언되어 있다.

편의를 위하여 Resize나 창 이동 시에는 timer를 정지한다.
실제 서비스 시에는 전부 계산한다.(복잡함)
