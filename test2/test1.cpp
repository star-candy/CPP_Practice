#include <iostream>
using namespace std;

class vector {
public:
	vector(int s) : sz{ s } {}

	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }

	int size() const { return sz; }

private:
	int sz;
	double elem[10];
};

int main() {
	int size = 0;
	cin >> size;

	vector v(size);

	for (int i = 0; i < v.size(); i++) {
		v.set(i, (double)i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v.get(i) << " ";
	}
	cout << endl;

	cout << "Good" << endl;

	return 0;
}
