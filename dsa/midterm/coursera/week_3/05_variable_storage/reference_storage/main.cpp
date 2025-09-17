#include <iostream>

int main() {
    int z = 50; // Direct storage
    int& ref = z; // Reference to z

    std::cout << "Value of z: " << z << std::endl; // Output: 50
    std::cout << "Value via reference: " << ref << std::endl; // Output: 50

    ref = 60; // Modify the value using the reference
    std::cout << "Modified value of z: " << z << std::endl; // Output: 60

    return 0;
}
