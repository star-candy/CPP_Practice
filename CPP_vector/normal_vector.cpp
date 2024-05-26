////#include "std_lib_facilities.h"
//#include <iostream>
//
//class vector {
//    int sz;
//    double* elem;
//public:
//    explicit vector(int s);//기본생성자, vector v = 1로 크기 1 벡터 생성 불가 키워드 explicit, size는 vector v1(7)로 설정
//
//    vector(std::initializer_list<double> lst);//생성 및 초기화 기능 생성자
//
//    ~vector() { delete[] elem; }//소멸자, 사용완료 시 elem이 가리키는 double 배열 공간 제거
//
//    double get(int n) const { return elem[n]; } //elem이 가리키는 배열 내 element를 index로 접근해 값 return
//    void set(int n, double v) { elem[n] = v; } //index로 배열 내 특정 위치의 값 초기화
//    int size() const { return sz; } //vector 크기 반환
//};
//
//vector::vector(int s) :sz(s), elem(new double[s]) {//double 배열 크기만큼 동적 할당, elem s *이 주소 가리킴
//    for (int i = 0; i < sz; i++) elem[i] = 0; //전체 배열 element를 0으로 초기화
//}
//vector::vector(std::initializer_list<double> lst) :sz{ static_cast<int>(lst.size()) }, elem{ new double[sz] } {//initializer로 초기화 할 값 배열로 받음
//    std::copy(lst.begin(), lst.end(), elem); //초기화 값 첫 주소부터, 마지막 주소까지, 차례로 elem 배열에 대입
//}
//
//int main() {
//
//    vector v1(20);
//    vector v2{ 1, 2, 3, 4, 5 };
//    return 0;
//}