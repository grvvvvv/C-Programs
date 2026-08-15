#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

Point addPoints(Point p1, Point p2) {
    Point temp(p1.x + p2.x, p1.y + p2.y);
    return temp; // Returning an object
}

int main() {
    Point p1(4, 5), p2(6, 7);
    Point p3 = addPoints(p1, p2);

    cout << "p1 = "; p1.display();
    cout << "p2 = "; p2.display();
    cout << "p3 (Sum) = "; p3.display();

    return 0;
}