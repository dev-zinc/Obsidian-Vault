#### Mass-Storage 종류
- [[Chapter 11#HDD|HDD]]
- [[Chapter 11#SSD|SSD]]
- [[Chapter 11#RAM Disk|RAM Disk]]
- [[Chapter 11#Magnetic Disk|Magnetic Disk]]
#### Disk Attatchment 방식
- Host Attached
- Network Attatched
## Network Attatched
#### NAS
- Network Attached Storage
- IP를 통해 접근
- File 단위로 접근
- 논리적으로 하나의 디스크로서 간주됨
- NFS, CIFS 등의 파일 시스템 사용
#### SAN
- Storage-Area Network
- storage array로 이루어짐
- Block 단위로 접근
- GFS 등의 파일 시스템 사용

SAN은 Network-Attatched Storage가 아니므로 외부 접근시 이를 관리하는 서버가 필요하다.

## Host Attached
#### HDD
- Disk Controller를 기준으로 추상화가 이루어짐
- 성능은 Seek Time에 의존함
- `Seek time` ~ `Seek Distance` (Arm 움직인 거리)
#### Disk Schedulling
- 들어오는 Disk Access에 대해 Seek Time을 최소화하는 것
#### FCFS
- 비효율적
#### SSTF
- 현재 head에서 가장 가까운 곳 선택
- 가까운 데이터가 매우 많은 경우 멀리 있는 데이터에 대하여 Starvation을 발생시킬 수 있음
#### SCAN
- elevator algorithm
- 0까지 갔다가 끝 주소까지 왼쪽 또는 오른쪽으로만 (시계/반시계)으로만 순회
- 데이터 간 대기시간이 균일하지 못함
#### C-SCAN
- 한 방향으로만 순회
#### LOOK, C-LOOK
- 끝까지 순회하지 않고 가장 끝 데이터에서 방향 전환

---
#### Swap-Space 관리

## RAID
- Redundant Array of Inexpensive Disks
- 저렴한 하드 디스크를 묶어 분산 스토리징하는 것
#### Data Stripping
- bit-level
	- bit 단위로 디스크에 분산
- block-level
	- block 단위로 디스크에 분산
#### RAID 0
- 중복 없는 stripping
- 따라서 안정성 떨어지나 성능은 좋음
	- 분산된 수만큼 안정성 하락
	- 하나라도 깨지면 그 데이터는 사망
	- 예) 4개 -> 1/4배 안정성
#### RAID 1
- 1회 백업
- 4개 분산 시 4개의 추가 백업 디스크 사용
- 본 디스크와 백업 디스크의 Parellel을 통한 약간의 성능 향상 가능
- 그러나 디스크 오버헤드가 큼
#### RAID 2
- error-correcting code (ECC)를 저장하는 디스크 사용
- 1보다 디스크는 줄어들지만 복구라는 과정 상에서 CPU 자원 사용
- 그러나 bit-level stripping을 사용하므로 사용하지 않음
	- bit strapping은 block strapping에 비하여 Spacial Locality가 매우 떨어짐
#### RAID 3
- Bit-interleaved parity
- parity bit 사용하여 2보다 Disk 오버헤드 작음
- 그러나 애석하게도 bit stripping
#### RAID 4
- Block-interleaved parity
- 쓰기 시간에 Parity Disk에 작업이 집중되어 과부하 및 쓰기 시간 지연 발생
#### RAID 5
- Block-interleaved distributed parity
- 한 Disk에 몰아넣은 parity bit가 아닌 분산된 parity bit
- 하나의 Disk가 망가져도 복구 가능
- 부하가 Uniform하므로 수명도 uniform할 수 있는 문제
- 5개 이상의 Disk 요구됨
#### RAID 6
- 2개 Disk 이상의 (분산) Parity 공간
- 6개 이상의 Disk 요구됨
## 대형 시스템에서의 RAID
#### RAID 0 + 1
- RAID 0을 먼저 사용하고, 그 전체를 1처럼 백업하여 사용
- RAID 0 내부 디스크 하나가 망가지면 해당 클러스터 전체를 사용 불가
	- 매우 비경제적
#### RAID 10
- RAID 1 + 0 
- 디스크 하나에 대해 1을 적용하고, 전체적으로는 0처럼 사용
- 01의 문제를 해결 가능

> RAID 1010 등으로 중첩하여 안정성을 더욱 높여 사용하기도 한다.