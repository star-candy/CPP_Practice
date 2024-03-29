#include "std_lib_facilities.h"

class Model
{
public:

    Model(int stick, int disk) {
        this->stick = stick;
        this->disk = disk;
        createHanoiTower();
    }

    void createHanoiTower() {
        vector<int> initTower;
        vector<int> empty;

        for (int i = disk; i > 0; i--) {
            initTower.push_back(i);
        }
        hanoiTower.push_back(initTower);

        for (int j = 0; j < stick; j++) {
            hanoiTower.push_back(empty);
        }
    }

    void verification(int existPosition, int changePosition) {
       


    }

    int getGameEndCount() { return gameEndCount; }

private:
    vector<vector<int>> hanoiTower;
    int stick;
    int disk;
    int gameEndCount = 1;
};



class View {
public:
    void inputInitialize();
    void inputMoveDisk(Model& model);
    bool inputReset();
    void outputDiskVisual();

    int getStick() { return stick; }
    int getDisk() { return disk; }

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
        if (stick < 3  || disk < 1 ) { //stick disk에 int가 아닌 값 입력 경우도 고려할 것
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
        cout << "From which tower will you move a disk to which tower ? (from = [1 | 2 | 3], to = [1 | 2 | 3]) :" << "\n";
        cin >> existPosition >> changePosition;
        if (existPosition > stick || changePosition > stick ) {//position에 int가 아닌 값 입력 경우도 고려할 것
            error("Input is out of stick range");
        }

        model.verification(existPosition, changePosition);

        moveCount++;
    }
    catch (runtime_error& e) {
        cout << e.what() << "\n";
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
void View::outputDiskVisual() {

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