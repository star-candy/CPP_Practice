## ��� ���


### view class

- i.o functions
  + [0] ����� ��ũ ������ �Է¹޴´� - inputInitialize
  + [0] �̵���� ��ƽ ��ġ�� �̵��� ��ƽ ��ġ�� �Է¹޴´� - inputMoveDisk
   ���� ���� �� => Move succeeded! ���� �� => Move failed!���� ��ȯ
  + [0] ���� ���� �� ���� ����� ���θ� �Է¹޴´� - inputReset
	
- game visualize functions
  + [0] vector�� �޾ƿ� �ϳ��� Ÿ���� �ð�ȭ -outputDiskVisual
	 
- getter
  + [0] ��ƽ�� ��ȯ - getStick
  + [0] ��ũ �� ��ȯ - getDisk 


### model class

- vector creator functions
  + [0] disk, stick ������ �°� ������ vector �ʱ�ȭ - createHanoiTower
 
- vector move functions
  + [0] �Է¹��� �̵� ��ƽ ��ġ�� ��Ģ ���� ���� �Ǵ� - verification
  + [0] �̵� ��� ��ġ���� �� ����, �̵� ��ġ�� �� �߰� moveHanoiTower
    ������ stick�� ��ġ�� ��ũ ������ ��ü ��ũ ���� �� ���� ���� ī���� ���� 
	 
- getter
  + [0] �ϳ��� Ÿ�� vector ��ȯ - getHanoiTower
  + [0] ���� ���� ī���� ��ȯ - getGameEndCount

	

### main (controller)
+ [0] �ϳ��� ž ���� ���� ���� ���
+ [0] ���� ���� ��ȯ ������ ��ũ ����
+ [0] ����� �Է� �� ó������, ���� �Է� �� ����


 ���� �ǵ� - class Ȱ�� �� ��ü�������μ��� ������ Ȯ��(mvc)
class ��ü�� �״�� ����� �������� ���� ���� 
class�� �������� ���Ͽ�

outputdiskVisual�� ��� hanoivector�� ���� �޴� �Ͱ� model ��ü�� �����ϴ� �� �� ���� ����
