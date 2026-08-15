#include <iostream>
using namespace std;

class Number {
public:
    int val;
    Number(int v) : val(v) {}
};

void swapObjects(Number &n1, Number &n2) {
    int temp = n1.val;
    n1.val = n2.val;
    n2.val = temp;
}

int main() {
    Number a(10), b(20);
    cout << "Before Swap: a = " << a.val << ", b = " << b.val << endl;
    swapObjects(a, b);
    cout << "After Swap:  a = " << a.val << ", b = " << b.val << endl;
    return 0;
}