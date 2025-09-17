#include <iostream>
#include <vector>

int main() {
    std::vector<int> int_list = {1, 2, 3};

    // Loop through each item and modify the original list
    for (int& x : int_list) {
        x = 99; // Change each item to 99
    }

    // Display the modified list
    for (int x : int_list) {
        std::cout << "This item has value: " << x << std::endl;
    }

    return 0;
}
