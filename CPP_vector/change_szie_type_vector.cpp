//#include "std_lib_facilities.h"
#include <iostream>

 class vector {
    int sz; //����ڰ� �����ϴ� vector size
    double* elem;
    int space; //���� �޸� �Ҵ� ũ��, ���� vector ȿ���� ���� sz �̻��� ũ�� �̸� �Ҵ�

public:
    vector();
    explicit vector(int s);
    vector(std::initializer_list<double> lst);

    vector(const vector&);
    vector& operator=(const vector& a); 

    vector(vector&&);//move-initialize
    vector& operator = (vector&&);//move - assignment

    double& operator[ ](int n) { return elem[n]; }

    void reserve(int newalloc);//element ����� ���� ���� �Լ�, �޸𸮿� ���� ��θ�
    void resize(int newsize);//element ���� ���� ��θ�, ���Ե��� ���� element �ʱ�ȭ 
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
    if (this == &a) return *this; //�ڽ� �״�� ���Խ� ���� ���� ���� �ʿ� ����

    if (a.sz <= space) { //���ԵǴ� ���� ũ�Ⱑ �ڽ� ���� ���϶�� ���� �� ���� ����� �ʿ� x
        for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz]; 
    for (int i = 0; i < a.sz; i++) p[i] = a.elem[i]; 
    delete[] elem; 
    sz = a.sz; 
    elem = p; 
    return *this; //�ڱ� �ڽ� ���� ���� ����, return �� ���� Ÿ������ ��� ���� v1 ���� ��ȯ
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

void vector::reserve(int newalloc) {//element ����� ���� �����ϴ� �Լ�
    if (newalloc <= space) return;//�����Ϸ��� ũ�Ⱑ ���� ũ�� �����̸� �״�� ��� ����
    double* p = new double[newalloc];
    for (int i = 0; i < sz; ++i) p[i] = elem[i];//���� ���� �迭�� ���� �� �ֱ�
    delete[] elem;//���� �迭 ����
    elem = p;
    space = newalloc;
}

void vector::resize(int newsize) {//�ʱ�ȭ ���� ���� element 0���� �ʱ�ȭ
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) elem[i] = 0;//���� ������ �ʱ�ȭ���� ���� �κ� ����, ���� ũ����� 0���� �ʱ�ȭ
    sz = newsize;//����ڰ� �ν��ϴ� ���� ũ�� ����
    //newsize�� sz���� ���� ���. �ʱ�ȭ x, ������ ��� ������ �� �߸�, sz = newsize��
}

void vector::push_back(double d) {
    if (sz == 0) reserve(8); //�ܼ� ���� ���Ͷ� ����x �� ���Ƿ� 8ũ�⸸ŭ �޸� �Ҵ�
    else if (sz == space) reserve(2 * space); //���� ���� �� ����� ��� �ι� ���� ����

    elem[sz] = d; //���� ũ�� +1 �κп� push back�� ����
    ++sz; //����� ���� ũ�� �ø�

}

int main() {

    vector v1(20);
    vector v2{ 1, 2, 3, 4, 5 };
    return 0;
}