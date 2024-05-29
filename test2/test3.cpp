#include <iostream>
using namespace std;

class vector {
public:
	vector(int s) : sz{ s }, elem{ new double[s] } {}
	~vector() { delete[] elem; }

	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }

	int size() const { return sz; }

private:
	int sz;
	double* elem;
};

void f(vector v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.get(i) << " ";
	}
	cout << endl;
}

int main() {
	vector v(10);

	for (int i = 0; i < v.size(); i++) {
		v.set(i, (double)i);
	}

	f(v);

	cout << "Good" << endl;

	return 0;
}
