#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, sub;
    cout << "Enter full line of text: ";
    getline(cin, text);

    cout << "Enter substring to search: ";
    cin >> sub;

    size_t first = text.find(sub);
    size_t last = text.rfind(sub);

    if (first == string::npos) {
        cout << "Substring not found in the given text.\n";
    } else {
        cout << "First occurrence index: " << first << endl;
        cout << "Last occurrence index:  " << last << endl;
    }

    return 0;
}