#include <iostream>

int main() {
    int y = 30; // Direct storage
    int* ptr = &y; // Pointer to y

    std::cout << "Value of y: " << y << std::endl; // Output: 30
    std::cout << "Value via pointer: " << *ptr << std::endl; // Output: 30

    *ptr = 40; // Modify the value using the pointer
    std::cout << "Modified value of y: " << y << std::endl; // Output: 40

    return 0;
}
