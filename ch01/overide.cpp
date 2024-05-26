//#include "std_lib_facilities.h"
//
//struct B {
//    virtual void f() const { cout << "b::f\n"; }
//    void g() const { cout << "b::g\n\n"; }
//};
//
//struct D : B {
//    void f() const { cout << "d::f\n"; }//override 조건 충족
//    void g() { cout << "d::g\n\n"; }//override 조건 x
//};
//
//struct DD : D {
//    void f() { cout << "dd::f\n"; }//x
//    void g() const { cout << "dd::g\n\n"; }//x
//};
//
//void call(const B& b) {//ref, ptr 타입으로 부모에 자식 대입시에만 override 가능 (기본사항 충족시)
//    b.f();
//    b.g();
//}
//
//int main() {
//    B b;
//    D d;
//    DD dd;
//
//    call(b); call(d); call(dd); //부모 주소 통한 함수 호출시 override 가능지점의 함수 출력될것
//
//    b.f(); b.g();//하위 직접 접근은 해당사항 x
//    d.f(); d.g();
//    dd.f();
//    dd.g();
//
//
//    return 0;
//}