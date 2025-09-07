#include <iostream>

struct Cube {
    int length;
    int volume() { return length * length * length; }
};

int main() {
    Cube* c = new Cube;   // heap allocation
    c->length = 4;        // sets the Cube's member variable 'length'
    std::cout << c->length << std::endl;    // prints 4
    std::cout << c->volume() << std::endl;  // calls the Cube's method 'volume()'

    return 0;
}

