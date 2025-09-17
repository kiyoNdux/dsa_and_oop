#include <iostream>

class MyClass {
public:
    // Constructor
    MyClass() {
        std::cout << "Constructor: Object created." << std::endl;
    }

    // Custom Destructor
    ~MyClass() {
        std::cout << "Destructor: Object destroyed." << std::endl;
    }
};

int main() {
    MyClass obj; // Object is created, constructor is called
    // When the function ends, the destructor will be called automatically
    return 0; // Object goes out of scope, destructor is called
}
