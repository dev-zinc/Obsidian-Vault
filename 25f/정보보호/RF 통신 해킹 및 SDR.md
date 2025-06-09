## RF 통신
- Radio Frequency
- 무선 통신
## RF 통신 해킹
- Wifi, Bluetooth 등 물리 계층에서 일어나는 해킹
- 그 특성상 아무나 주파수를 도청가능하므로 특히 암호화 등 보안이 중요
#### 대표적 공격기법
- Eavesdropping
	- wireshark가 해당 기능을 함
- Replay Attack
	- 암호화된 패킷을 수신자에게 해커가 한 번 더 보내는 것
	- 내용은 알 수 없지만 여러 번의 명령이 일어나게 함
- MITM
	- Man-in-The-Middle
	- Burpsuite가 해당 기능을 함
- Signal Manipulation & Spoofing
	- 신호 조작 및 스푸핑
## RF 통신의 원리
#### 신호 송신
- 큰 세기, 적당한 주파수, 적당한 대역푹
- 데이터 -> 신호 변환
- 변조(Modulation) 및 증폭
- 안테나를 통한 송신
#### 신호 수신
- 신호 감쇠, 노이즈 처리
- 특정 주파수만 수신
- 신호를 복조(Demodulation)
- 신호 -> 데이터 변환
#### 주파수
- 수 Mhz ~ GHz 대역 사용
- 낮을수록 멀리, 높을수록 넓은 대역폭
- 너무 낮으면 데이터를 많이 못 담음
#### 대역폭
- 사용 가능한 주파수 범위
- 넓을수록 더 많은 데이터를 한번에 전송 가능
## 변조
- 데이터를 RF 신호에 담는 과정
- AM, FM 등 여러 방법
#### Carrier Signal
- 원래 신호
- 여기에 Modulation을 걸어 송신
### Analog Modulation
- 음성과 같은 연속적인 신호 변조
#### AM
- Amplitude Modulation
- 진폭에 데이터를 기록
#### FM
- Frequency Modulation
- 주파수에 데이터를 기록
#### PM
- Phase Modulation
- 위상에 데이터를 기록
### Digital Modulation
- 펄스와 같은 이산적인 변조
#### ASK
- 진폭 변환
- 0, 1을 특정 진폭에 매핑
#### FSK
- 주파수 변환
- 0, 1을 특정 주파수에 매핑
#### PSK
- 위상 변환
- 0, 1을 특정 위상에 매핑
#### QAM
- 진폭과 위상을 동시에 사용하여 전송
- Constellation Diagram으로 위상 변조를 표현
- (0, 0) 으로부터의 거리 == 진폭
- X축 양의 방향을 기준으로 한 각도 == 위상 
- 매핑 개수에 따라 2-QAM, 4-QAM 등 존재
- 매핑 개수가 늘어날수록 정보 밀도는 높아지나 오류 발생 가능성이 증가함![[Pasted image 20250602154510.png]]
#### 복조
- 변조된 신호를 다시 데이터로 복구하는 과정
### RF 신호 해석
- Frequency Domain
	- FSK 해석
- Time Domain
	- 펄스 형태 확인
- Waterfall Plot (Spectogram)
	- 신간에 따른 주파수, 진폭 표현
	- 신호의 존재유무
- Constellation Diagram
	- 위상, 진폭을 점찍음
	- QAM 신호 해석
## SDR
- Software Defined Radio
- 다양한 RF 신호 구현 가능

