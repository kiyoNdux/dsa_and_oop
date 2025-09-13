#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
string customer_queue[MAX_SIZE];
int queue_size = 0;

void showMenu() {
    cout << "===== Banking Queue System =====" << endl;
    cout << "[1] Add Customer to Queue" << endl;
    cout << "[2] Serve Next Customer" << endl;
    cout << "[3] Show Queue" << endl;
    cout << "[0] Exit" << endl;
    cout << "Enter your choice: ";
}


void add_customer(string customer_name) {
    if (queue_size < MAX_SIZE) {
        customer_queue[queue_size] = customer_name;
        queue_size++;
        cout << customer_name << " added to the queue." << endl;
    } else {
        cout << "Queue is full. Cannot add more customers." << endl;
    }
}


int main() {
    int user_choice;
    do {
        showMenu();
        cin >> user_choice;

        if (user_choice == 1) {
            string new_customer;
            cout << "Enter customer name: ";
            cin >> new_customer;
            add_customer(new_customer);
        } else if (user_choice == 2) {
            continue;
        } else if (user_choice == 3) {
            continue;
        } else if (user_choice == 0) {
            cout << "Exiting system..." << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    } while (user_choice != 0);

    return 0;
}
