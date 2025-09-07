#include <iostream>
using namespace std;

int main() {
    int *numPtr = new int; // assign a pointer to a heap

    cout << "*numPtr: " << *numPtr << endl; // check what the value inside (should be something random) greater than heaps memory
    cout << " numPtr: " <<  numPtr << endl; // check the heaps memory less that pointer memory
    cout << "&numPtr: " << &numPtr << endl; // check the pointers memory

    *numPtr = 42; // Assign 42 value to the heap using the numPtr
    cout << "*numPtr assigned 42." << endl;

    cout << "*numPtr: " << *numPtr << endl; // check the new value (should be 42)
    cout << " numPtr: " <<  numPtr << endl; // check the heaps memory again
    cout << "&numPtr: " << &numPtr << endl; // check the current pointer memory

    return 0;
}
