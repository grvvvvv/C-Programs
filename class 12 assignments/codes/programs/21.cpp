#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Record {
    int id;
    char name[50];
    float marks;
};

void logMessage(const string& msg) {
    ofstream logFile("log.txt", ios::app);
    if (logFile) {
        logFile << msg << endl;
    }
}

void addRecord(int id, const char* name, float marks) {
    ofstream out("records.dat", ios::binary | ios::app);
    if (!out) {
        cout << "Error opening binary file!\n";
        return;
    }
    Record r;
    r.id = id;
    strncpy(r.name, name, sizeof(r.name) - 1);
    r.name[sizeof(r.name) - 1] = '\0';
    r.marks = marks;

    out.write(reinterpret_cast<char*>(&r), sizeof(Record));
    out.close();
    logMessage("Added record with ID: " + to_string(id));
}

void queryRecord(int id) {
    ifstream in("records.dat", ios::binary);
    if (!in) {
        cout << "Binary file not found!\n";
        return;
    }
    Record r;
    bool found = false;
    while (in.read(reinterpret_cast<char*>(&r), sizeof(Record))) {
        if (r.id == id) {
            cout << "Found -> ID: " << r.id << ", Name: " << r.name << ", Marks: " << r.marks << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Record with ID " << id << " not found.\n";
    in.close();
}

void updateMarks(int id, float newMarks) {
    fstream file("records.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File error!\n";
        return;
    }
    Record r;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&r), sizeof(Record))) {
        if (r.id == id) {
            r.marks = newMarks;
            file.seekp(-static_cast<streamoff>(sizeof(Record)), ios::cur);
            file.write(reinterpret_cast<char*>(&r), sizeof(Record));
            found = true;
            logMessage("Updated ID " + to_string(id) + " with new marks: " + to_string(newMarks));
            cout << "Record updated.\n";
            break;
        }
    }
    if (!found) cout << "ID not found for update.\n";
    file.close();
}

int main() {
    addRecord(101, "Alice", 88.5);
    addRecord(102, "Bob", 92.0);

    cout << "Querying ID 101:\n";
    queryRecord(101);

    cout << "\nUpdating Marks for ID 101:\n";
    updateMarks(101, 95.0);

    cout << "\nQuerying ID 101 after update:\n";
    queryRecord(101);

    return 0;
}