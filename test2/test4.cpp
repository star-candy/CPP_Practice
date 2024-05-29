#include <iostream>
using namespace std;

class vector {
public:
	vector(int s) : sz{ s }, elem{ new double[s] } {}
	~vector() { delete[] elem; }

	vector(const vector& v) : sz{ v.size() }, elem{ new double[sz] } {
		for (int i = 0; i < sz; i++) {
			set(i, v.get(i));
		}
		num_copy_constructions++;
	}

	vector& operator=(const vector& v) {
		if (this == &v) {
			return *this;
		}
		delete[] elem;

		sz = v.size();
		elem = new double[sz];

		for (int i = 0; i < sz; i++) {
			set(i, v.get(i));
		}
		num_copy_assignments++;

		return *this;
	}

	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }

	int size() const { return sz; }

	static int getNumCopyConstuctions() { return num_copy_constructions; }
	static int getNumCopyAssignments() { return num_copy_assignments; }

private:
	int sz;
	double* elem;

	static int num_copy_constructions;
	static int num_copy_assignments;
};

int vector::num_copy_constructions = 0;
int vector::num_copy_assignments = 0;

vector f(vector v) {
	vector v_new(v.size());

	for (int i = 0; i < v.size(); i++) {
		v_new.set(i, v.get(i) + 1.0);
	}

	return v_new;
}

int main() {
	int num_counts = 0;
	cin >> num_counts;

	vector v(10);

	for (int i = 0; i < v.size(); i++) {
		v.set(i, (double)i);
	}

	for (int i = 0; i < num_counts; i++) {
		v = f(v);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v.get(i) << " ";
	}
	cout << endl;

	cout << "# of copy constructions = " << vector::getNumCopyConstuctions() << endl;
	cout << "# of copy assignments = " << vector::getNumCopyAssignments() << endl;

	return 0;
}
