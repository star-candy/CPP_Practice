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
//	Rect() : width(0), height(0) {}
//	Rect(double w, double h) : width(w), height(h) {}
//
//	double getWidth() const { return width; }
//	double getHeight() const { return height; }
//
//	void setSize(double w, double h) { width = w; height = h; }
//
//private:
//	double width, height;
//};
//
//ostream& operator<<(ostream& os, const Rect& r)
//{
//	os << "(x: " << r.getX() << ", y: " << r.getY() << ", color: " << r.getColor() << ", width: " << r.getWidth() << ", height: " << r.getHeight() << ")";
//
//	return os;
//}
//
//struct Circle : Shape
//{
//
// 
//};
//
//ostream& operator<<(ostream& os, const Circle& c)
//{

//}
//
//int main() {
//	Rect rect{ 10, 20 };
//	Circle circle{ 15 };
//
//	cout << "Initial state:" << endl;
//	cout << "- Rect = " << rect << endl;
//	cout << "- Circle = " << circle << endl;
//
//	rect.setPos(10, 5);
//	rect.setColor(Color::red);
//	rect.setSize(30, 15);
//
//	circle.setPos(-5, 20);
//	circle.setColor(Color::blue);
//	circle.setRadius(25);
//
//	cout << "Final state: " << endl;
//	cout << "- Rect = " << rect << endl;
//	cout << "- Circle = " << circle << endl;
//
//	return 0;
//}