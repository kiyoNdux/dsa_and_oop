#include <iostream>
#include <vector>

int main() {
    std::vector<int> int_list = {1, 2, 3};

    // Loop through each item without modifying the original list
    for (int x : int_list) {
        std::cout << "This item has value: " << x << std::endl;
    }

    return 0;
}
