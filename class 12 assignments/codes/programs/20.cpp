#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
public:
    Book(string t, string a) : title(t), author(a) {
        cout << "Book Created: \"" << title << "\" by " << author << endl;
    }

    ~Book() {
        cout << "Book Destroyed: \"" << title << "\" by " << author << endl;
    }

    void display() const {
        cout << "Title: " << title << " | Author: " << author << endl;
    }
};

int main() {
    {
        // Creating the first 3 parts of Harry Potter
        Book b1("Harry Potter and the Sorcerer's Stone", "J.K. Rowling");
        Book b2("Harry Potter and the Chamber of Secrets", "J.K. Rowling");
        Book b3("Harry Potter and the Prisoner of Azkaban", "J.K. Rowling");

        cout << "\n--- Displaying Books ---\n";
        b1.display();
        b2.display();
        b3.display();
        cout << "------------------------\n\n";

    } // All 3 books go out of scope here and their destructors are triggered
    
    cout << "End of main scope.\n";
    return 0;
}
