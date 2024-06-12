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
//ostream& operator<<(ostream& os, const Shape& s)
//{
//	os << "(" << s.getX() << ", " << s.getY() << ", " << s.getColor() << ")";
//
//	return os;
//}
//
//struct Rect : Shape
//{
//	
//};
//
//ostream& operator<<(ostream& os, const Rect& r)
//{
//
//}
//
//int main() {
//	Rect rect1, rect2(10, 20);
//
//	cout << "Initial state:" << endl;
//	cout << "- Rect1 = " << rect1 << endl;
//	cout << "- Rect2 = " << rect2 << endl;
//
//	rect1.setPos(10, 5);
//	rect1.setColor(Color::red);
//	rect1.setSize(30, 15);
//
//	rect2.setPos(-5, 20);
//	rect2.setColor(Color::blue);
//	rect2.setSize(5, 25);
//
//	cout << "Final state: " << endl;
//	cout << "- Rect1 = " << rect1 << endl;
//	cout << "- Rect2 = " << rect2 << endl;
//
//	return 0;
//}