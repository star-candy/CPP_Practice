#include <iostream>
using namespace std;

class vector {
public:
	vector(int s) : sz{ s }, elem{ new double[s] } {}

	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }

	int size() const { return sz; }

private:
	int sz;
	double* elem;
};

int main() {
	int num_counts = 0;
	cin >> num_counts;

	for (int i = 0; i < num_counts; i++) {
		vector v(1000);
		for (int j = 0; j < v.size(); j++) {
			v.set(j, 0.0);
		}
	}

	cout << "Good" << endl;

	return 0;
}
