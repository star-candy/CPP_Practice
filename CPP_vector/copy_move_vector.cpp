////#include "std_lib_facilities.h"
//#include <iostream>
//
//class vector {
//    int sz;
//    double* elem;
//public:
//    explicit vector(int s);
//    vector(std::initializer_list<double> lst);
//
//    //ptr�� ����Ǵ� shallow copy ���� �ذ� -> deep copy ���� ���� ���
//    vector(const vector&); //vector a = b�������� ������ ���Ϳ� ���� ���� ����, copy-initialize ���� �ذ� ������
//    //���� �� ���� ���� ���𿡼��� ��� ��
//    vector& operator=(const vector& a); //�̹� ������ �� ���� ���Խ� copy-assignment ���� �ذ� �����ε�
//    //vector ���� Ÿ�� �������� ���� ���Կ��� ��� ���� v1 = v2 = v3
//    
//    //copy�� �����Ҵ� �� �������� �ڿ� �Ҹ� ����, �����Ǹ� �����ϸ� �Ǵ� ��� && Ű����� move ��Ȳ���� ȣ��� 
//    vector(vector&&);//move-initialize
//    vector& operator = (vector&&);//move - assignment
//    //���� ���� �Ҵ� ���� �״�� ���
//
//    //double* operator[ ](int n) { return &elem[n]; }//�а� ���⸦ []�����ڸ� ���� �����ϰ�
//    //but ��� �� *v[1] = 3 ó�� �� ������ ����ؾ� ��, ���� �����͸� ��ȯ��
//    double& operator[ ](int n) { return elem[n]; }
//    //ref Ÿ�� ��ȯ �� ������ ���� ���� ��� ����
//
//
//    double get(int n) const { return elem[n]; } 
//    void set(int n, double v) { elem[n] = v; } 
//    int size() const { return sz; } 
//
//    ~vector() { delete[] elem; }
//};
//
//vector::vector(int s) :sz(s), elem(new double[s]) {
//    for (int i = 0; i < sz; i++) elem[i] = 0; 
//}
//vector::vector(std::initializer_list<double> lst) :sz{ static_cast<int>(lst.size()) }, elem{ new double[sz] } { 
//    std::copy(lst.begin(), lst.end(), elem);  
//}
//vector::vector(const vector& a) :sz{ a.sz }, elem{ new double[a.sz] } // elem�� ������ �������� �����Ҵ� �Ͽ�, copy-initialize ���� �ذ�
//{
//    for (int i = 0; i < sz; i++) elem[i] = a.elem[i]; //���ԵǴ� ���� element�� ���� ���� �� ����
//}
//vector& vector::operator=(const vector& a) { //copy - assignment�� ���� delete, ���� ��� ���� ���� �ذ�
//    double* p = new double[a.sz]; //v1 = v2���� v2 ��ŭ�� ũ�� �Ҵ�
//    for (int i = 0; i < a.sz; i++) p[i] = a.elem[i]; //v2���� �ִ� ���� p�迭�� �̵�
//    delete[] elem; //���� v1�� ������ �ּ� �迭 ����
//    sz = a.sz; //v2 ũ�� ����
//    elem = p; //s2 ���ڸ� ���� p �ּҸ� ���Ҵ�
//    
//    return *this; //�ڱ� �ڽ� ���� ���� ����, return �� ���� Ÿ������ ��� ���� v1 ���� ��ȯ
//}
//
//vector::vector(vector&& a) :sz{ a.sz }, elem{ a.elem } {//move - initialize ���� �ذ� ���� ������
//    a.sz = 0;
//    a.elem = nullptr;//a�� ������ ����, a�� elem ptr ���� �� ������ ����
//}
//vector& vector::operator=(vector&& a) {//move - assignment �ذ�, v1 = v2 = v3 ���� ���� ���� ��ȯ Ÿ�� ���
//    //v1 = v2���� ���� v1 ���� ����, v2 �Ҵ� �� v2 ������ ���� �ʿ�
//    delete[] elem; // v1 = v2���� v1 ���� ����
//    elem = a.elem; // v1�� v2 �ּ� ����
//    sz = a.sz; //v1�� v2 ũ�� ����
//    a.elem = nullptr;//v2 �迭�� ������ ����
//    a.sz = 0;
//    return *this; //���� Ÿ�� ��ȯ
//}
//
//int main() {
//
//    vector v1(20);
//    vector v2{ 1, 2, 3, 4, 5 };
//    return 0;
//}