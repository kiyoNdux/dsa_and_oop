#include <iostream>    // For input/output operations
using namespace std;   // Allows usage of standard library names without std:: prefix

class Stack {
private:
    int top;            // Index of the topmost element in the stack
    int maxSize;        // Maximum number of elements the stack can hold
    string* stackArray; // Pointer to dynamically allocated array that holds stack elements


public:
    // Constructor to initialize stack
    Stack(int size) {
        maxSize = size;                    // Set the maximum size
        stackArray = new string[maxSize];  // Dynamically allocate memory for stack
        top = -1;                          // Initialize stack as empty
    }


    // Destructor to cleanup the allocated memory
    ~Stack() {
        delete[] stackArray;  // Frees the dynamically allocated array
    }


    bool isEmpty() {
        return (top == -1);  // True if there are no elements
    }

    bool isFull() {
        return (top == maxSize - 1);  // True if stack reached its max capacity
    }


    void push(string value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push \"" << value << "\"." << endl;
        } else {
            stackArray[++top] = value;  // Increment top and insert value
        }
    }


    string pop() {
        if (isEmpty()) {
            return "";                 // Return empty string if stack is empty
        } else {
            return stackArray[top--];  // Return top element, then decrement top
        }
    }


    string peek() {
        if (isEmpty()) {
            return "";             // Return empty string if stack is empty
        } else {
            return stackArray[top]; // Return the top element without removing it
        }
    }
};


int main() {
    Stack backStack(5);      // Stack to store previously visited pages
    Stack forwardStack(5);   // Stack to store pages available for forward navigation
    string currentPage = "Home";  // Default starting page


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

            backStack.push(currentPage);  // Save current page to back history
            currentPage = newPage;        // Move to the new page

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
                forwardStack.push(currentPage); // Save current page to forward history
                currentPage = backStack.pop();  // Go to the last page in back history
                cout << "Went back to: " << currentPage << endl;
            }
        }

        else if (choice == 3) {
            if (forwardStack.isEmpty()) {
                cout << "No pages in forward history." << endl;
            } else {
                backStack.push(currentPage);   // Save current page to back history
                currentPage = forwardStack.pop(); // Move to forward page
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
