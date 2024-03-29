#include "std_lib_facilities.h"


class View {
public:
    void inputInitialize();
    void inputMoveDisk();
    bool inputReset();
    void outputDiskVisual();

    int getStick() { return stick; }
    int getDisk() { return disk; }

private:
    int stick = 0;
    int disk = 0;
    int moveCount = 1;
};

void View::inputInitialize() {
    try {
        cout << "막대와 디스크의 개수를 입력해주세요" << "\n";
        cin >> stick >> disk;
        if (stick < 3 || sizeof(stick) != 4 || disk < 1 || sizeof(disk) != 4) {
            error("Input failed!");
        }
    }
    catch (runtime_error& e) {
        cout << e.what() << "\n";
        inputInitialize();
    }
}

void View::inputMoveDisk() {
    try {
        cout << "[" << moveCount << "]";
        cout << "From which tower will you move a disk to which tower ? (from = [1 | 2 | 3], to = [1 | 2 | 3]) :" << "\n";
        //model생성자에 input 입력해 초기화
        moveCount++;
    }
    catch (runtime_error& e) {
        cout << e.what() << "\n";
        inputMoveDisk();
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