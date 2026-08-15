#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() const {
        cout << "Base Shape area undefined.\n";
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void area() const override {
        cout << "Area of Circle with radius " << radius 
             << " = " << 3.14159 * radius * radius << endl;
    }
};

int main() {
    Shape* shapePtr;
    Circle c(7.0);

    shapePtr = &c;
    shapePtr->area(); // Dynamic dispatch

    return 0;
}