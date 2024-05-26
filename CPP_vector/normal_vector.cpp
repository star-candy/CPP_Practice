////#include "std_lib_facilities.h"
//#include <iostream>
//
//class vector {
//    int sz;
//    double* elem;
//public:
//    explicit vector(int s);//�⺻������, vector v = 1�� ũ�� 1 ���� ���� �Ұ� Ű���� explicit, size�� vector v1(7)�� ����
//
//    vector(std::initializer_list<double> lst);//���� �� �ʱ�ȭ ��� ������
//
//    ~vector() { delete[] elem; }//�Ҹ���, ���Ϸ� �� elem�� ����Ű�� double �迭 ���� ����
//
//    double get(int n) const { return elem[n]; } //elem�� ����Ű�� �迭 �� element�� index�� ������ �� return
//    void set(int n, double v) { elem[n] = v; } //index�� �迭 �� Ư�� ��ġ�� �� �ʱ�ȭ
//    int size() const { return sz; } //vector ũ�� ��ȯ
//};
//
//vector::vector(int s) :sz(s), elem(new double[s]) {//double �迭 ũ�⸸ŭ ���� �Ҵ�, elem s *�� �ּ� ����Ŵ
//    for (int i = 0; i < sz; i++) elem[i] = 0; //��ü �迭 element�� 0���� �ʱ�ȭ
//}
//vector::vector(std::initializer_list<double> lst) :sz{ static_cast<int>(lst.size()) }, elem{ new double[sz] } {//initializer�� �ʱ�ȭ �� �� �迭�� ����
//    std::copy(lst.begin(), lst.end(), elem); //�ʱ�ȭ �� ù �ּҺ���, ������ �ּұ���, ���ʷ� elem �迭�� ����
//}
//
//int main() {
//
//    vector v1(20);
//    vector v2{ 1, 2, 3, 4, 5 };
//    return 0;
//}