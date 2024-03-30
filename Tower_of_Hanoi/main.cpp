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
        error("동일한 위치로 이동할 수 없습니다.");
    }
    if (hanoiTower[existPosition].empty()) {
        error("해당 위치에 디스크가 없습니다.");
    }
    else {
        existPositionValue = hanoiTower[existPosition].back(); //위치 검사 이후 변수생성으로 벡터 범위 오류 방지
    }

    if (hanoiTower[changePosition].empty()) {
        changePositionValue = disk + 1; // 변경할 스틱 내에 디스크가 없다면 큰값 넣어 디스크간 크기비교시 오류 방지
    }
    else {
        changePositionValue = hanoiTower[changePosition].back();
    }

    if (existPositionValue > changePositionValue) {
        error("큰 디스크를 작은 디스크 위에 올릴 수 없습니다.");
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
        cout << "막대와 디스크의 개수를 입력해주세요" << "\n";
        cin >> stick >> disk;

        if (stick < 3 || disk < 1) { //stick disk에 int가 아닌 값 입력 경우도 고려할 것
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
        if (existPosition > stick || changePosition > stick ) {//position에 int가 아닌 값 입력 경우도 작성 할것
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
    cout << "하노이의 탑 게임을 시작합니다" << "\n";
    do {
        View view; // View class 객체 생성
        view.inputInitialize();
        Model model(view.getStick(), view.getDisk()); //Model class 객체 생성 및 하노이 탑 초기화

        while (model.getGameEndCount()) {//1로 초기화 / 게임 완료 시 0 return
            view.inputMoveDisk(model); //model 객체 참조
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