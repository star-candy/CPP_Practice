## 기능 목록


### view class

- i.o functions
  + [0] 막대와 디스크 개수를 입력받는다 - inputInitialize
  + [0] 이동대상 스틱 위치와 이동할 스틱 위치를 입력받는다 - inputMoveDisk
   문제 없을 시 => Move succeeded! 문제 시 => Move failed!에러 반환
  + [0] 게임 종료 후 게임 재시작 여부를 입력받는다 - inputReset
	
- game visualize functions
  + [0] vector을 받아와 하노이 타워로 시각화 -outputDiskVisual
	 
- getter
  + [0] 스틱값 반환 - getStick
  + [0] 디스크 값 반환 - getDisk 


### model class

- vector creator functions
  + [0] disk, stick 개수에 맞게 이차원 vector 초기화 - createHanoiTower
 
- vector move functions
  + [0] 입력받은 이동 스틱 위치의 규칙 위반 여부 판단 - verification
  + [0] 이동 대상 위치에서 값 삭제, 이동 위치에 값 추가 moveHanoiTower
    마지막 stick에 위치한 디스크 개수와 전체 디스크 동일 시 게임 종료 카운터 변경 
	 
- getter
  + [0] 하노이 타워 vector 반환 - getHanoiTower
  + [0] 게임 종료 카운터 반환 - getGameEndCount

	

### main (controller)
+ [0] 하노이 탑 게임 시작 문구 출력
+ [0] 게임 종료 반환 전까지 디스크 변경
+ [0] 재시작 입력 시 처음부터, 종료 입력 시 종료


 구현 의도 - class 활용 및 객체지향으로서의 독립성 확보(mvc)
class 객체를 그대로 사용할 것인지에 대한 보고서 
class간 독립성에 대하여

outputdiskVisual에 경우 hanoivector를 직접 받는 것과 model 객체를 참조하는 것 중 선택 이유
