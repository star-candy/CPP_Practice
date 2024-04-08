#include "std_lib_facilities.h"

class Model {
public:

    Model(int stick, int disk) {
        this->stick = stick;
        this->disk = disk;
        createHanoiTower();
    }
    
    void verification(int existPosition, int changePosition);
    void moveHanoiTower(int existPosition, int changePosition);

    vector<vector<int>> getHanoiTower();
    bool getGameEndCount();

private:
    void createHanoiTower();
    vector<vector<int>> hanoiTower;
    int stick;
    int disk;
    bool gameEndCount = true;
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
        gameEndCount = false;
    }
}
vector<vector<int>> Model::getHanoiTower() {
    return hanoiTower;
}
bool Model::getGameEndCount() {
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �Է� ���� ����
            error("=> �������� ���� �ԷµǾ�� �մϴ�.");
        }
     
        if (stick < 2) { 
            error("=> 2�� �̻��� ���밡 �ԷµǾ�� �մϴ�.");
        }
        if (disk < 1) {
            error("=> 1���� ���� ��ũ ���� �Էµ� �� �����ϴ�.");
        }
        if (stick < disk) {
            error("=> ��ũ�� ������ ���뺸�� ���� �� �����ϴ�.");
        }
        if (stick == 2 && disk == 2) {
            error("=> 2*2 ������ ����� �� �����ϴ�.");
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �Է� ���� ����
            error("�������� ���� �ԷµǾ�� �մϴ�.");
        }

        if (existPosition > stick || changePosition > stick ) {
            error("���� �������� ū ���� �Էµ� �� �����ϴ�.");
        }
        if (existPosition < 1 || changePosition < 1) {
            error("0������ ��ġ�� �̵��� �� �����ϴ�");
        }
        if (existPosition == changePosition) {
            error("������ ��ġ�� �̵��� �� �����ϴ�.");
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
    cout << "Congratulation! You solved it in " << moveCount - 1 << "moves!" << "\n";
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
    const vector<vector<int>>& hanoiTower = model.getHanoiTower();
    for (int i = 0; i < stick; i++) {
        cout << '[' << i + 1 << ']';

        if (hanoiTower[i].empty()) {
            cout << "-------------" << "\n";
            continue;
        }
        for (int disk : hanoiTower[i]) {
            while (disk > 0) {
                cout << "|";
                disk--;
            }
            cout << "-";
        }
        cout << "\n";
    }
    //�⺻ ��� ���
    /*for (int i = 0; i < stick; i++) { 
        cout << '[' << i + 1 << ']';
        for (int disk : hanoiTower[i]) {
            cout << disk << " ";
        }
        cout << "\n";
    }*/
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
