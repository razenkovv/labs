#include <iostream>
#include "Vector.h"
#include "List.h"
#include "Matrix.h"
//#include <Vector>

class Point {
public:
    double x, y;

    Point(double _x, double _y) : x(_x), y(_y) {}
    Point() : x(0.0), y(0.0) {}

    void print() {
        std::cout << x << " " << y << std::endl;
    }

    friend std::ostream& operator<<(std::ostream &out, const Point &point);
};

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << point.x << " " << point.y;
    return out;
}

int main() {
//    List<double> a(2,1);
//    a.push_front(2);
//    a.push_back(3);
//    a.push_front(1.2);
//    a.push_back(2.3);
//    a.push_back(3.4);
//    a.push_front(3.5);
//    a.push_front(8.9);
//    std::cout << "Size: " << a.size() << std::endl;
//    std::cout << "8.9 3.5 1.2 2 1 1 3 2.3 3.4 \n\n";
//    a.print();
//
//    Point p1(1.2, 5.6);
//    Point p2(3.4, 5.5);
//    List<Point> l;
//    l.push_front(p1);
//    l.push_back(p2);
//    l.push_back(p1);
//    l.push_back(p2);
//    l.push_front(p2);
//
//    const int n = 5;
//    double xx[n]{1.2, 4.4, 3.4, 4.5, 6.7};
//    Vector<double> a(n, xx);
//    a.reserve(100);
//    std::cout << "a " << a.size() << " " << a.capacity() << std::endl;
//    a.print();
//    std::cout << std::endl;
//    Vector<double> b(a);
//    std::cout << "b " << b.size() << " " << b.capacity() << std::endl;
//    b.print();

    try {
        Matrix<double> b(3, 3, 1.5);
        b.print();
        return 0;
    } catch (const char *msg) {
        std::cout << msg;
    }
}