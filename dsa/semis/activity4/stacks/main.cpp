#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    string* stackArray;

public:
    // Constructor to initialize stack
    Stack(int size) {
        maxSize = size;
        stackArray = new string[maxSize];
        top = -1; // Stack is initially empty
    }

    // Destructor to cleanup the allocated memory
    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == maxSize - 1);
    }

    void push(string value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push \"" << value << "\"." << endl;
        } else {
            stackArray[++top] = value;
        }
    }

    string pop() {
        if (isEmpty()) {
            return "";
        } else {
            return stackArray[top--];
        }
    }

    string peek() {
        if (isEmpty()) {
            return "";
        } else {
            return stackArray[top];
        }
    }
};

// Real-world example: Web browser navigation
int main() {
    Stack backStack(5);
    Stack forwardStack(5);
    string currentPage = "Home";

    int choice;
    string newPage;

    while (true) {
        cout << "\nBrowser Navigation" << endl;
        cout << "Current page: " << currentPage << endl;
        cout << "1. Visit new page" << endl;
        cout << "2. Go back" << endl;
        cout << "3. Go forward" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page name: ";
            cin >> newPage;

            backStack.push(currentPage);
            currentPage = newPage;

            // Clear forward stack when visiting new page
            while (!forwardStack.isEmpty()) {
                forwardStack.pop();
            }

            cout << "Visited: " << currentPage << endl;
        }
        else if (choice == 2) {
            if (backStack.isEmpty()) {
                cout << "No pages in back history." << endl;
            } else {
                forwardStack.push(currentPage);
                currentPage = backStack.pop();
                cout << "Went back to: " << currentPage << endl;
            }
        }
        else if (choice == 3) {
            if (forwardStack.isEmpty()) {
                cout << "No pages in forward history." << endl;
            } else {
                backStack.push(currentPage);
                currentPage = forwardStack.pop();
                cout << "Went forward to: " << currentPage << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting browser simulation..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
