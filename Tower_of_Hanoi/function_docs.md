## 기능 목록
### view class

- i.o functions
  + [0] 막대, 디스크 개수 입출력
  + [0] 디스크 위치 변경 입출력 
  + [0] 게임 종료 재시작 입출력

- game visualize functions
  + [] 디스크 시각화 출력

- [0] stick, disk getter function
- [0] 디스크 이동 횟수에 대한 변수
- [0] stick, disk 반환 위한 변수

### model class

- vector creator functions
  + [0] stick, disk 개수에 맞게 vector 생성 및 초기화
 
### inputVerification function
 사용자의 입력이 현재 벡터에 유효한지 판단한다. (existPosition, changePosition 활용)
  +	[0] 입력받은 위치정보 크기가 stick의 개수내에 있는가 (inputMoveDisk 실행)
  + [] 입력받은 위치정보가 int형이 맞는가 (inputMoveDisk 실행할 것)
	
  + [0] existPosition에 벡터값이 존재하는가(디스크 존재 여부 판단)
  + [0] changePosition에 있는 값이 existPosition의 값보다 작은가 (작을 경우 게임 규칙 위반)
	
  + [0] 마지막 백터에 전체 디스크가 존재할 경우 model.gameEndCount = 0으로 변경

	
-판단 문제 없을 시 벡터 변환 후 => Move succeeded!
-판단 문제 시 => Move failed! 출력 후 에러 반환

	


### main function
+ [0] 하노이 탑 게임 시작 문구 출력
+ [0] 게임 종료 반환 전까지 디스크 변경
+ [0] 재시작 입력 시 처음부터, 종료 입력 시 종료

### 기능 요구 사항

- 막대 개수와 디스크의 개수를 입력받는다. (단 막대 개수는 3개 이상이어야 한다.)
- 현재 막대, 디스크 상태를 시각화 한다.
- 디스크를 옮길 위치를 입력받는다. (몇 번째 입력인지 출력할 것)
- 사용자가 잘못된 값을 입력할 경우 에러를 출력하고 재입력 받는다.
- 막대의 위치를 조정하고 상태를 시각화 한다.
- 첫번째 막대에서 마지막 막대로 모든 디스크가 옮겨지면 종료 메세지를 출력한다
- 재시작 종료 여부를 입력받는다.

