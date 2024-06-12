//#include <iostream>
//#include <cmath>
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
//	Circle() : radius(0) {}
//	Circle(double r) : radius(r) {}
//
//	double getRadius() const { return radius; }
//	void setRadius(double r) { radius = r; }
//

//private:
//	double radius;
//};
//
//ostream& operator<<(ostream& os, const Circle& c)
//{
//	os << "(x: " << c.getX() << ", y: " << c.getY() << ", color: " << c.getColor() << ", radius: " << c.getRadius() << ")";
//
//	return os;
//}
//
//int main() {
//	Rect rect(10, 20);
//	Circle circle(15);
//
//	cout << "Area of rect = " << rect.calcArea() << endl;
//	cout << "Area of circle = " << circle.calcArea() << endl;
//
//	return 0;
//}
