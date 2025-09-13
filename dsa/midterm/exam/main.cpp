#include <iostream>
using namespace std;

void showMenu() {
    cout << "===== Banking Queue System =====" << endl;
    cout << "[1] Add Customer to Queue" << endl;
    cout << "[2] Serve Next Customer" << endl;
    cout << "[3] Find Customer in Queue" << endl;
    cout << "[4] Sort Queue (by Priority)" << endl;
    cout << "[5] Show Queue" << endl;
    cout << "[0] Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int main() {
    showMenu();
    return 0;
}
