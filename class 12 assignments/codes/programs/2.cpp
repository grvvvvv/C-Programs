#include <iostream>
using namespace std;

class Base {
private:
    int priv = 10;
protected:
    int prot = 20;
public:
    int pub = 30;

    int getPrivate() { return priv; }
};

class Derived : public Base {
public:
    void display() {
        // priv is not directly accessible
        cout << "Accessing private via Base method: " << getPrivate() << endl;
        cout << "Accessing protected member: " << prot << endl;
        cout << "Accessing public member: " << pub << endl;
    }
};

int main() {
    Derived obj;
    obj.display();
    cout << "Direct public access from main: " << obj.pub << endl;
    return 0;
}