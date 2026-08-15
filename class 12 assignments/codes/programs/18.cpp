#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int* ptr = &num;

    cout << "Value of num directly: " << num << endl;
    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Value accessed via pointer (*ptr): " << *ptr << endl;

    *ptr = 99;
    cout << "Value after modifying via pointer: " << num << endl;

    return 0;
}