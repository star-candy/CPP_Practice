#include "View.h"

void Output::printPurchasedLotto(vector<vector<int>>& purchasedLotto) {

    for(const auto& row : purchasedLotto) {
        for (int col : row) { // int& col ���� const���� ���Ҵ�Ǿ� ���� �߻��ϴµ�
            cout << col << " ";
        }
        cout << endl;
    }
}

void Output::printWinningStatics(vector<int>& winningStatics, double profitRate) { //5~1�� ��÷ ������ ���� vector
    cout << "��÷ ���" << endl << "---" << endl;
    cout << "3�� ��ġ (5,000��) - " << winningStatics[0] << "��" << endl;
    cout << "4�� ��ġ (50,000��) - " << winningStatics[1] << "��" << endl;
    cout << "5�� ��ġ (1,500,000��) - " << winningStatics[2] << "��" << endl;
    cout << "5�� ��ġ, ���ʽ� �� ��ġ (30,000,000��) - " << winningStatics[3] << "��" << endl;
    cout << "6�� ��ġ (2,000,000,000��) - " << winningStatics[4] << "��" << endl;
    cout << "�� ���ͷ��� " << profitRate << "�Դϴ�." << endl;
}
