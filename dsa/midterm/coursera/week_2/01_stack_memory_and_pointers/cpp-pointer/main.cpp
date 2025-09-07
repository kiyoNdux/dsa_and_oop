#include <iostream>
using namespace std;

int main() {
    int num = 7;
    cout << "num: " << num << endl;
    cout << "&num: " << &num << endl;

    int *p = &num;
    cout << "p: " << p << endl;
    cout << "&p: " << &p << endl;
    cout << "*p: " << *p << endl;

    *p = 42;
    cout << "*p changed to 42" << endl;
    cout << "num: " << num << endl;

    return 0;

}
