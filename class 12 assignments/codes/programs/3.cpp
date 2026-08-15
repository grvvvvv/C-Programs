#include <iostream>
#include <string>
using namespace std;

class Item {
    int id;
    string name;
    float price;
public:
    void getItem() {
        cout << "Enter Item ID, Name, and Price: ";
        cin >> id >> name >> price;
    }
    void putItem() const {
        cout << "ID: " << id << " | Name: " << name << " | Price: Rs " << price << endl;
    }
};

int main() {
    Item items[5];
    for (int i = 0; i < 5; i++) {
        cout << "Item " << i + 1 << ":\n";
        items[i].getItem();
    }

    cout << "\n--- ITEM DETAILS ---\n";
    for (int i = 0; i < 5; i++) {
        items[i].putItem();
    }
    return 0;
}