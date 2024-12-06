# VLAN

- 물리적 배치와 관계없이 *논리적으로* LAN을 구성
- 동일한 VLAN Number를 가지면 같은 LAN에 속함
- 물리적 연결보다 우선시됨

기본적으로, `Flooding`은 오버헤드이다. 따라서 네트워크 사이즈에 따라 손실이 커진다.

> `# show vlan`

![alt text](show-vlan.png)
이처럼 모두 기본적으로는 `Default VLAN`에 속한 것을 볼 수 있다.
[[Virtual Local Area Network|VLAN]]을 나누게 되면 보안성이 향상된다.(기본포트 바꾸는 것과 같은 이치)
## TRUNK Port
모든 [[Virtual Local Area Network|VLAN]]이 통신할 수 있는 포트.
큰 네트워크에서는 반드시 Bottle Neck 현상이 생기므로, [[Switch#Asymmetric Switching|Asymmetric Switching]]이 필요한 경우가 생긴다.

> [!warning] 
> TRUNK Port를 지날 때 Snipping 위험 등 보안상 취약점이 존재한다.

다음과 같은 Extended Topology에서 각 Switch 간을 지나는 통신을 위해 필요하다.
![alt text](vlan-top.png)

이를 막기 위해 [[Virtual Local Area Network|VLAN]] 수만큼 Switch 사이에 포트를 두는 경우도 있다.
![alt text](trunk.png)
## Inter-VLAN
- 라우터를 기반으로 서로 다른 [[Virtual Local Area Network|VLAN]] 장치끼리 통신할 수 있게 해주는 방법
- 가상 인터페이스 SVI`(Switch Virtual Interface)`를 구성하고 각 VLAN에 Default Gateway 구현

![[Pasted image 20241204144952.png]]

위와 같은 네트워크에서 10번 , 20번 VLAN에 대한 Inter-VLAN Routing은 다음과 같이 설정 가능하다.
```router
# config VLAN 10
Router(config)# int fa0/0.10
Router(config-subif)#encapsulation dot1q 10
Router(config-subif)#ip add 203.230.7.1 255.255.255.0

# config VLAN 20
Router(config)# int fa0/0.20
Router(config-subif)#encapsulation dot1q 20
Router(config-subif)#ip add 203.230.8.1 255.255.255.0
```

 

