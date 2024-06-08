//#include <iostream>
//using namespace std;
//
//enum class Color {
//	black, red, green, blue, white
//};
//
//ostream& operator<<(ostream& os, Color c)
//{
//	switch (c) {
//	case Color::black: os << "Black"; break;
//	case Color::red: os << "Red"; break;
//	case Color::green: os << "Green"; break;
//	case Color::blue: os << "Blue"; break;
//	case Color::white: os << "White"; break;
//	}
//	return os;
//}
//
//struct Shape
//{
//	Shape() : x(0), y(0), color(Color::white) {}
//
//	double getX() const { return x; }
//	double getY() const { return y; }
//	Color getColor() const { return color; }
//
//	void setPos(double xx, double yy) { x = xx; y = yy; }
//	void setColor(Color c) { color = c; }
//
//private:
//	double x, y;
//	Color color;
//};
//
//ostream& operator <<(ostream& os, const Shape& s) {
//	os << "(" << s.getX() << ", " << s.getY() << ", " << s.getColor() << ")";
//	return os;
//}
//
//int main() {
//	Shape shape;
//
//	cout << "Initial state: " << shape << endl;
//
//	shape.setPos(10, 5);
//	shape.setColor(Color::red);
//
//	cout << "Final state: " << shape << endl;
//
//	return 0;
//}
