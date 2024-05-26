#include "std_lib_facilities.h"

struct B {
    virtual void f() const { cout << "b::f\n"; }
    virtual void g() const { cout << "b::g\n\n"; }
};

struct D : B {
    void f() const { cout << "d::f\n"; }//override ���� ����
    void g() { cout << "d::g\n\n"; }//override ���� x
};

struct DD : D {
    void f() const { cout << "dd::f\n"; }//x
    void g() const { cout << "dd::g\n\n"; }//x
};

void call(const B& b) {//ref, ptr Ÿ������ �θ� �ڽ� ���Խÿ��� override ���� (�⺻���� ������)
    b.f();
    b.g();
}

int main() {
    B b;
    D d;
    DD dd;

    b = d;
    b.f();
    b.g();

    call(b); call(d); call(dd); //�θ� �ּ� ���� �Լ� ȣ��� override ���������� �Լ� ��µɰ�

    b.f(); b.g();//���� ���� ������ �ش���� x
    d.f(); d.g();
    dd.f();
    dd.g();


    return 0;
}