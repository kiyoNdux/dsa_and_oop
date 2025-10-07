#include <iostream>
#define STACK_H
using namespace std;

int main() {
    class Stack {
    private:
        int top;
        int maxSize;
        int * stackArray;

    public:
        // Constructor to initialize stack
        Stack(int size) {
            maxSize = size;
            stackArray = new int[maxSize];
            top = -1; // Stack is initially empty
        }

        // Destructor to cleanup the allocated memory
        ~Stack() {
            delete[] stackArray;
        }

        // Function to check if the stack is empty
        bool isEmpty() {
            return (top == -1);
        }

        // Function to check if the stack is full
        bool isFull() {
            return (top == maxSize - 1);
        }

        // Function to push an element onto the stack
        void push(int value) {
            if (isFull()) {
                cout << "Stack is full. Cannot push " << value << "." << endl;
            } else {
                stackArray[++top] = value;
                cout << "Pushed" << value << " onto the stack." << endl;
            }
        }

        // Function to pop an element from the stack
        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty. Cannot pop." << endl;
            } else {
                cout << "Popped " << stackArray[top--] << "from the stack." << endl;
            }
        }

        // Function to peek the top element of the stack
        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty. Nothing to peek." << endl;
                return -1; // Return -1 if stack is empty
            } else {
                return stackArray[top];
            }
        }
    };
}
