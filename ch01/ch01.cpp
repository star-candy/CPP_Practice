#include "std_lib_facilities.h"
#include "test.h"


int main() 
try {
    Test test;
    test.testError();

    return 0;
}
catch (runtime_error& e) {
    cout << "runtime_error : " << e.what() << "\n";
    keep_window_open();
    return 1;

}


