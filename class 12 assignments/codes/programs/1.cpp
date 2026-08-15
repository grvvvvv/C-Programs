#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

int main() {
    Student s[5];
    int topperIndex = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Enter Roll, Name, and Marks for student " << i + 1 << ": ";
        cin >> s[i].roll >> s[i].name >> s[i].marks;
        if (s[i].marks > s[topperIndex].marks) {
            topperIndex = i;
        }
    }

    cout << "\n--- TOPPER DETAILS ---\n";
    cout << "Roll: " << s[topperIndex].roll 
         << " | Name: " << s[topperIndex].name 
         << " | Marks: " << s[topperIndex].marks << endl;

    int searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (s[i].roll == searchRoll) {
            cout << "Student Found -> Name: " << s[i].name 
                 << ", Marks: " << s[i].marks << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Student with Roll Number " << searchRoll << " not found.\n";

    return 0;
}
