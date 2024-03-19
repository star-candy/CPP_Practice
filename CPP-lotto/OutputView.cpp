#include "View.h"

void Output::printPurchasedLotto(vector<vector<int>>& purchasedLotto) {

    for(const auto& row : purchasedLotto) {
        for (int col : row) { // int& col 사용시 const값이 재할당되어 오류 발생하는듯
            cout << col << " ";
        }
        cout << endl;
    }
}

void Output::printWinningStatics(vector<int>& winningStatics, double profitRate) { //5~1등 당첨 개수에 대한 vector
    cout << "당첨 통계" << endl << "---" << endl;
    cout << "3개 일치 (5,000원) - " << winningStatics[0] << "개" << endl;
    cout << "4개 일치 (50,000원) - " << winningStatics[1] << "개" << endl;
    cout << "5개 일치 (1,500,000원) - " << winningStatics[2] << "개" << endl;
    cout << "5개 일치, 보너스 볼 일치 (30,000,000원) - " << winningStatics[3] << "개" << endl;
    cout << "6개 일치 (2,000,000,000원) - " << winningStatics[4] << "개" << endl;
    cout << "총 수익률은 " << profitRate << "입니다." << endl;
}
