//#include "std_lib_facilities.h"
#include <iostream>

 class vector {
    int sz; //사용자가 인지하는 vector size
    double* elem;
    int space; //실제 메모리 할당 크기, 가변 vector 효율성 위해 sz 이상의 크기 미리 할당

public:
    vector();
    explicit vector(int s);
    vector(std::initializer_list<double> lst);

    vector(const vector&);
    vector& operator=(const vector& a); 

    vector(vector&&);//move-initialize
    vector& operator = (vector&&);//move - assignment

    double& operator[ ](int n) { return elem[n]; }

    void reserve(int newalloc);//element 저장된 공간 변경 함수, 메모리에 대한 고민만
    void resize(int newsize);//element 개수 대한 고민만, 대입되지 않은 element 초기화 
    void push_back(double d);

    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n] = v; }
    int size() const { return sz; }
    int capacity() const { return space; }

    ~vector() { delete[] elem; }
};

 vector::vector() : sz{ 0 }, elem{ 0 }, space{ 0 } {}
 vector::vector(int s) :sz{ s }, elem{ new double[s] }, space{ s } {
    for (int i = 0; i < sz; i++) elem[i] = 0;
}
 vector::vector(std::initializer_list<double> lst) :sz{ static_cast<int>(lst.size()) }, elem{ new double[sz] }, space{ sz } {
    std::copy(lst.begin(), lst.end(), elem);
}
 vector::vector(const vector& a) :sz{ a.sz }, elem{ new double[a.sz] }, space{ a.sz }
{
    for (int i = 0; i < sz; i++) elem[i] = a.elem[i];
}
vector& vector::operator=(const vector& a) {
    if (this == &a) return *this; //자신 그대로 대입시 복사 대입 연산 필요 없음

    if (a.sz <= space) { //대입되는 벡터 크기가 자신 공간 이하라면 굳이 새 공간 재생성 필요 x
        for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz]; 
    for (int i = 0; i < a.sz; i++) p[i] = a.elem[i]; 
    delete[] elem; 
    sz = a.sz; 
    elem = p; 
    return *this; //자기 자신 대한 간접 연산, return 시 참조 타입으로 사용 가능 v1 참조 반환
}

vector::vector(vector&& a) :sz{ a.sz }, elem{ a.elem }, space{ a.sz } {
    a.sz = 0;
    a.elem = nullptr;
}
vector& vector::operator=(vector&& a) {
    delete[] elem; 
    elem = a.elem; 
    sz = a.sz; 
    a.elem = nullptr;
    a.sz = 0;
    return *this; 
}

void vector::reserve(int newalloc) {//element 저장된 공간 변경하는 함수
    if (newalloc <= space) return;//지정하려는 크기가 기존 크기 이하이면 그대로 사용 가능
    double* p = new double[newalloc];
    for (int i = 0; i < sz; ++i) p[i] = elem[i];//새로 지정 배열에 기존 값 넣기
    delete[] elem;//기존 배열 제거
    elem = p;
    space = newalloc;
}

void vector::resize(int newsize) {//초기화 되지 않은 element 0으로 초기화
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) elem[i] = 0;//이전 값으로 초기화되지 않은 부분 부터, 공간 크기까지 0으로 초기화
    sz = newsize;//사용자가 인식하는 공간 크기 변경
    //newsize가 sz보다 작을 경우. 초기화 x, 오히려 사용 가능한 값 잘림, sz = newsize로
}

void vector::push_back(double d) {
    if (sz == 0) reserve(8); //단순 생성 벡터라 공간x 시 임의로 8크기만큼 메모리 할당
    else if (sz == space) reserve(2 * space); //실제 공간 다 사용한 경우 두배 공간 생성

    elem[sz] = d; //기존 크기 +1 부분에 push back값 제공
    ++sz; //사용자 인지 크기 늘림

}

int main() {

    vector v1(20);
    vector v2{ 1, 2, 3, 4, 5 };
    return 0;
}