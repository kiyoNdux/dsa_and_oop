#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    for (int i = 0; i<100; i++) {
        v.push_back(i * i);
    }

    for (int j = 0; j<v.size(); j++) {
        std::cout << "\nIndex " << j << v[j] << " ";
    }

    std::cout << "\nIndex 12: " << v[12] << std::endl;

    return 0;
}
