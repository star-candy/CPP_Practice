#include "std_lib_facilities.h"

class Model {
public:

    Model(int stick, int disk) {
        this->stick = stick;
        this->disk = disk;
        createHanoiTower();
    }

    void createHanoiTower();
    void verification(int existPosition, int changePosition);
    void moveHanoiTower(int existPosition, int changePosition);

    vector<vector<int>> getHanoiTower();
    int getGameEndCount();

private:
    vector<vector<int>> hanoiTower;
    int stick;
    int disk;
    int gameEndCount = 1;
};

void Model::createHanoiTower() {
    vector<int> initTower;
    vector<int> empty;

    for (int i = disk; i > 0; i--) {
        initTower.push_back(i);
    }
    hanoiTower.push_back(initTower);

    for (int j = 1; j < stick; j++) {
        hanoiTower.push_back(empty);
    }
}
void Model::verification(int existPosition, int changePosition) {
    --existPosition, --changePosition;
    int existPositionValue = 0, changePositionValue = 0;

    if (existPosition == changePosition) {
        error("������ ��ġ�� �̵��� �� �����ϴ�.");
    }
    if (hanoiTower[existPosition].empty()) {
        error("�ش� ��ġ�� ��ũ�� �����ϴ�.");
    }
    else {
        existPositionValue = hanoiTower[existPosition].back(); //��ġ �˻� ���� ������������ ���� ���� ���� ����
    }

    if (hanoiTower[changePosition].empty()) {
        changePositionValue = disk + 1; // ������ ��ƽ ���� ��ũ�� ���ٸ� ū�� �־� ��ũ�� ũ��񱳽� ���� ����
    }
    else {
        changePositionValue = hanoiTower[changePosition].back();
    }

    if (existPositionValue > changePositionValue) {
        error("ū ��ũ�� ���� ��ũ ���� �ø� �� �����ϴ�.");
    }
}
void Model::moveHanoiTower(int existPosition, int changePosition) {
    --existPosition, --changePosition;
    int valueBuffer = hanoiTower[existPosition].back();;
    hanoiTower[existPosition].pop_back();
    hanoiTower[changePosition].push_back(valueBuffer);

    if (hanoiTower[stick - 1].size() == disk) {
        gameEndCount = 0;
    }
}
vector<vector<int>> Model::getHanoiTower() {
    return hanoiTower;
}
int Model::getGameEndCount() {
    return gameEndCount;
}


class View {
public:
    void inputInitialize();
    void inputMoveDisk(Model& model);
    bool inputReset();
    void outputDiskVisual(Model& model);

    int getStick();
    int getDisk();

private:
    int stick = 0;
    int disk = 0;
    int moveCount = 1;
    int existPosition = 0;
    int changePosition = 0;
};

void View::inputInitialize() {
    try {
        cout << "����� ��ũ�� ������ �Է����ּ��� : ";
        cin >> stick >> disk;
        cout << "\n";

        if (stick < 3 || disk < 1) { //stick disk�� int�� �ƴ� �� �Է� ��쵵 ����� ��
            error("Input failed!");
        }
    }
    catch (runtime_error& e) {
        cout << e.what() << "\n";
        inputInitialize();
    }
}
void View::inputMoveDisk(Model& model) {
    try {
        cout << "[" << moveCount << "]";
        cout << "From which tower will you move a disk to which tower ? (from = [1 | 2 | 3], to = [1 | 2 | 3]) : ";
        cin >> existPosition >> changePosition;
        if (existPosition > stick || changePosition > stick ) {//position�� int�� �ƴ� �� �Է� ��쵵 �ۼ� �Ұ�
            error("Input is out of stick range");
        }
        if (existPosition < 1 || changePosition < 1) {
            error("Input zero or negative value");
        }

        model.verification(existPosition, changePosition);
        model.moveHanoiTower(existPosition, changePosition);
        cout << "=> " << "Move succeeded!" << "\n\n";

        moveCount++;
    }
    catch (runtime_error& e) {
        cout << "=> " << "Move failed! ";
        cout << e.what() << "\n\n";
        inputMoveDisk(model);
    }
}
bool View::inputReset() {
    char restartCount;
    cout << "Congratulation! You solved it in " << moveCount << "moves!" << "\n";
    cout << "Do you want to play again? (Y/S):";
    cin >> restartCount;

    switch (restartCount) {
    case '1': case 'Y': case 'y':
        return true;

    case '0': case 'S': case 's': case 'N': case 'n':
        return false;

    default:
        error("bad restart count");
        return false;
    }
}
void View::outputDiskVisual(Model& model) {
    const vector<vector<int>> &hanoiTower = model.getHanoiTower();
    for (int i = 0; i < stick; i++) {
        cout << '[' << i + 1 << ']';
        for (int disk : hanoiTower[i]) {
            cout << disk << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}
int View::getStick() {
    return stick;
}
int View::getDisk() {
    return disk;
}


int main()
try {
    bool restartCount = false;
    cout << "�ϳ����� ž ������ �����մϴ�" << "\n";
    do {
        View view; // View class ��ü ����
        view.inputInitialize();
        Model model(view.getStick(), view.getDisk()); //Model class ��ü ���� �� �ϳ��� ž �ʱ�ȭ
        view.outputDiskVisual(model); //�ʱ� �ϳ��� Ÿ�� ���
        while (model.getGameEndCount()) {//1�� �ʱ�ȭ / ���� �Ϸ� �� 0 return
            view.inputMoveDisk(model); //model ��ü ����
            view.outputDiskVisual(model);
        }
        restartCount = view.inputReset();
    } while (restartCount);

    keep_window_open();
    return 0;
}
catch (runtime_error& e) {
    cout << "runtime_error : " << e.what() << "\n";
    keep_window_open();
}
catch (...) {
    cout << "something error" << "\n";
    keep_window_open();
}


/*void printHanoiTower(int stick, const std::vector<std::vector<int>>& hanoiTower) {
    // ������ �ִ� ���� ���
    int maxHeight = 0;
    for (const auto& rod : hanoiTower) {
        maxHeight = std::max(maxHeight, static_cast<int>(rod.size()));
    }

    // ��ũ�� �߾� �����Ͽ� ���
    for (int height = maxHeight - 1; height >= 0; --height) {
        for (int i = 0; i < stick; ++i) {
            if (hanoiTower[i].size() > height) {
                // ��ũ ũ�⿡ ���� '-' ��� (�߾� ����)
                int diskSize = hanoiTower[i][height];
                int padding = (stick - diskSize) / 2;
                std::cout << std::setw(padding + diskSize) << std::setfill('-') << std::setw(stick - padding) << ' ';
            } else {
                // ��ũ�� ���� ��� ��ĭ ���
                std::cout << std::setw(stick) << ' ';
            }
        }
        std::cout << std::endl;
    }
    // �� ���� ���� ����
    std::cout << std::string(stick * maxHeight, '=') << std::endl;
}*/