//#include "std_lib_facilities.h"
#include <iostream>

class vector {
    int sz;
    double* elem;
public:
    explicit vector(int s);
    vector(std::initializer_list<double> lst);

    //ptr이 복사되는 shallow copy 문제 해결 -> deep copy 구현 위한 기능
    vector(const vector&); //vector a = b형식으로 생성된 벡터에 기존 벡터 대입, copy-initialize 문제 해결 생성자
    //인자 뒤 변수 명은 선언에서는 없어도 됨
    vector& operator=(const vector& a); //이미 생성된 두 벡터 대입시 copy-assignment 문제 해결 오버로딩
    //vector 참조 타입 리턴으로 연속 대입에도 사용 가능 v1 = v2 = v3
    

    ~vector() { delete[] elem; } 

    double get(int n) const { return elem[n]; } 
    void set(int n, double v) { elem[n] = v; } 
    int size() const { return sz; } 
};

vector::vector(int s) :sz(s), elem(new double[s]) {
    for (int i = 0; i < sz; i++) elem[i] = 0; 
}
vector::vector(std::initializer_list<double> lst) :sz{ static_cast<int>(lst.size()) }, elem{ new double[sz] } { 
    std::copy(lst.begin(), lst.end(), elem);  
}
vector::vector(const vector& a) :sz{ a.sz }, elem{ new double[a.sz] } // elem을 독립적 공간으로 동적할당 하여, copy-initialize 문제 해결
{
    for (int i = 0; i < sz; i++) elem[i] = a.elem[i]; //대입되는 벡터 element로 기존 벡터 값 대입
}

vector& vector::operator=(const vector& a) { //copy - assignment의 이중 delete, 대입 대상 누수 문제 해결
    double* p = new double[a.sz]; //v1 = v2에서 v2 만큼의 크기 할당
    for (int i = 0; i < a.sz; i++) p[i] = a.elem[i]; //v2내에 있는 인자 p배열로 이동
    delete[] elem; //기존 v1이 가지던 주소 배열 제거
    sz = a.sz; //v2 크기 대입
    elem = p; //s2 인자를 담은 p 주소를 재할당
    
    return *this; //자기 자신 대한 간접 연산, return 시 참조 타입으로 사용 가능 v1 참조 반환
}



int main() {

    vector v1(20);
    vector v2{ 1, 2, 3, 4, 5 };
    return 0;
}