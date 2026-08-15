#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename, ios::binary | ios::ate);
    if (!file) {
        cout << "Error opening file or file does not exist!\n";
        return 1;
    }

    streampos size = file.tellg();
    file.close();

    cout << "File Size: " << size << " bytes\n";
    return 0;
}