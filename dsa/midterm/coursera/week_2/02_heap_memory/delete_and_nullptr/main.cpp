#include <iostream>
using namespace std;

struct Cube {
    int length;
    int volume() { return length * length * length; }
};

int main() {
    // Allocate a Cube on the heap
    Cube* c = new Cube;
    c->length = 3;

    cout << "Volume: " << c->volume() << endl; // 27

    // Free the heap memory
    delete c;

    // At this point, c is a "dangling pointer"
    // It still holds the old address, but that memory no longer belongs to us.

    // To make it safe, set c to nullptr
    c = nullptr;

    // Now if we try to use c, it's obvious there's no object
    if (c == nullptr) {
        cout << "c is now safely null." << endl;
    }

    // Uncommenting the next line would cause a crash (segmentation fault):
    // cout << c->volume() << endl;

    return 0;
}
