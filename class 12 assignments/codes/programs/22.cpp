#include <iostream>
using namespace std;

// 1. Linear Stack using Fixed Array
class LinearStack {
    int top, cap;
    int arr[50];
public:
    LinearStack(int c = 10) : top(-1), cap(c) {}

    void push(int val) {
        if (top == cap - 1) { 
            cout << "Stack Overflow!\n"; 
            return; 
        }
        arr[++top] = val;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (top == -1) { 
            cout << "Stack Underflow!\n"; 
            return; 
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is Empty.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (top == -1) { 
            cout << "Stack is Empty.\n"; 
            return; 
        }
        cout << "Linear Stack (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// 2. Circular Stack using Array (With Wrap-around Logic)
class CircularStack {
    int top, cap, size;
    int arr[50];
public:
    CircularStack(int c = 10) : top(-1), cap(c), size(0) {}

    void push(int val) {
        if (size == cap) { 
            cout << "Circular Stack Overflow!\n"; 
            return; 
        }
        top = (top + 1) % cap;
        arr[top] = val;
        size++;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (size == 0) { 
            cout << "Circular Stack Underflow!\n"; 
            return; 
        }
        cout << "Popped: " << arr[top] << endl;
        top = (top - 1 + cap) % cap;
        size--;
    }

    void peek() {
        if (size == 0) {
            cout << "Circular Stack is Empty.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (size == 0) { 
            cout << "Circular Stack is Empty.\n"; 
            return; 
        }
        cout << "Circular Stack (Top to Bottom): ";
        int curr = top;
        for (int i = 0; i < size; i++) {
            cout << arr[curr] << " ";
            curr = (curr - 1 + cap) % cap;
        }
        cout << endl;
    }
};

// 3. Stack using Linked List
struct SNode {
    int data;
    SNode* next;
};

class LinkedStack {
    SNode* top;
public:
    LinkedStack() : top(nullptr) {}

    void push(int val) {
        SNode* newNode = new SNode();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (!top) { 
            cout << "Stack Underflow!\n"; 
            return; 
        }
        SNode* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (!top) {
            cout << "Stack is Empty.\n";
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    void display() {
        if (!top) { 
            cout << "Stack is Empty.\n"; 
            return; 
        }
        cout << "Linked Stack (Top to Bottom): ";
        for (SNode* p = top; p != nullptr; p = p->next) {
            cout << p->data << " -> ";
        }
        cout << "NULL\n";
    }

    // Destructor to clean up memory
    ~LinkedStack() {
        while (top != nullptr) {
            SNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    LinearStack ls;
    CircularStack cs;
    LinkedStack lks;
    int type, op, val;

    while (true) {
        cout << "\n===============================\n";
        cout << "          MAIN MENU            \n";
        cout << "===============================\n";
        cout << "1. Linear Stack (Array)\n";
        cout << "2. Circular Stack (Array)\n";
        cout << "3. Linked List Stack\n";
        cout << "4. Exit Program\n";
        cout << "Enter your choice (1-4): ";
        cin >> type;
        
        if (type == 4) break;
        if (type < 1 || type > 4) {
            cout << "Invalid choice! Please select 1-4.\n";
            continue;
        }

        while (true) {
            cout << "\n--- Operations Sub-Menu ---\n";
            cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Go back to Main Menu\n";
            cout << "Enter operation (1-5): ";
            cin >> op;
            
            if (op == 5) break;

            if (op == 1) {
                cout << "Enter value to push: ";
                cin >> val;
            }

            // Route to correct object based on selected main type
            if (type == 1) {
                if (op == 1) ls.push(val);
                else if (op == 2) ls.pop();
                else if (op == 3) ls.peek();
                else if (op == 4) ls.display();
                else cout << "Invalid operation!\n";
            } 
            else if (type == 2) {
                if (op == 1) cs.push(val);
                else if (op == 2) cs.pop();
                else if (op == 3) cs.peek();
                else if (op == 4) cs.display();
                else cout << "Invalid operation!\n";
            } 
            else if (type == 3) {
                if (op == 1) lks.push(val);
                else if (op == 2) lks.pop();
                else if (op == 3) lks.peek();
                else if (op == 4) lks.display();
                else cout << "Invalid operation!\n";
            }
        }
    }

    cout << "\nProgram exited successfully.\n";
    return 0;
}
