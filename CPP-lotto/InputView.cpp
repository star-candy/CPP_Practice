#include "View.h"

int Input::getPurchaseValue() {
    int purchaseValue;
    cout << "���Աݾ��� �Է��� �ּ���." << endl;
    cin >> purchaseValue;
    cout << purchaseValue << endl;
    cout << purchaseValue / 1000 << "���� �����߽��ϴ�.\n" << endl;
    return purchaseValue;
}

string Input::getWinningNumber() { 
    string winningNumber;
    cout << "��÷ ��ȣ�� �Է��� �ּ���." << endl;
    cin >> winningNumber;
    cout << winningNumber << endl;
    return winningNumber;
}

int Input::getBonusNumber() {
    int bonusNumber;
    cout << "���ʽ� ��ȣ�� �Է��� �ּ���." << endl;
    cin >> bonusNumber;
    cout << bonusNumber << endl;
    return bonusNumber;
}