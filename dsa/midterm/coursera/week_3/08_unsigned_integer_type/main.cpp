#include <iostream>
#include <vector>

int main() {
    unsigned int x = 10;
    unsigned int y = 20;

    // Demonstrating subtraction with unsigned integers
    std::cout << "y - x = " << (y - x) << std::endl; // Expected output: 10
    std::cout << "x - y = " << (x - y) << std::endl; // Unexpected output: a large positive number

    // Casting the result to signed int
    int result = static_cast<int>(x - y);
    std::cout << "Casting x - y to signed int gives: " << result << std::endl; // Expected output: -10

    // Example with a vector
    std::vector<int> v = {1, 2, 3, 4};
    for (unsigned int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl; // Safe to use unsigned here
    }

    return 0;
}
