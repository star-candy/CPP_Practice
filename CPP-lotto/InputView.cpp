#include "View.h"

int Input::getPurchaseValue() {
    int purchaseValue;
    cout << "구입금액을 입력해 주세요." << endl;
    cin >> purchaseValue;
    cout << purchaseValue << endl;
    cout << purchaseValue / 1000 << "개를 구입했습니다.\n" << endl;
    return purchaseValue;
}

string Input::getWinningNumber() { 
    string winningNumber;
    cout << "당첨 번호를 입력해 주세요." << endl;
    cin >> winningNumber;
    cout << winningNumber << endl;
    return winningNumber;
}

int Input::getBonusNumber() {
    int bonusNumber;
    cout << "보너스 번호를 입력해 주세요." << endl;
    cin >> bonusNumber;
    cout << bonusNumber << endl;
    return bonusNumber;
}