#pragma once
#include "Common.h"

class Input {

public:
    int getPurchaseValue();
    string getWinningNumber();
    int getBonusNumber();
};

class Output {

public:
    void printPurchasedLotto(vector<vector<int>> purchasedLotto);
    void printWinningStatics(vector<int> winningStatics);
    void printProfitRate(int profitRate);
};