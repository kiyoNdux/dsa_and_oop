#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
string customer_queue[MAX_SIZE];
int queue_size = 0;


void showMenu() {
    cout << "===== Banking Queue System =====" << endl;
    cout << "[1] Add Customer to Queue" << endl;
    cout << "[2] Serve Next Customer" << endl;
    cout << "[3] Find Customer in Queue" << endl;
    cout << "[4] Sort Queue (by Priority)" << endl;
    cout << "[5] Show Queue" << endl;
    cout << "[6] Insert Customer at Position" << endl;
    cout << "[0] Back to Main Menu" << endl;
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


void serve_next_customer() {
    if (queue_size > 0) {
        cout << "Serving customer: " << customer_queue[0] << endl;
        for (int i = 1; i < queue_size; i++) {
            customer_queue[i - 1] = customer_queue[i];
        }
        queue_size--;
    } else {
        cout << "No customers in queue." << endl;
    }
}


int find_customer(string customer_name) {
    for (int i = 0; i < queue_size; i++) {
        if (customer_queue[i] == customer_name) {
            return i;
        }
    }
    return -1;
}


void sort_queue() {
    if (queue_size > 0) {
        for (int i = 0; i < queue_size - 1; i++) {
            for (int j = 0; j < queue_size - i - 1; j++) {
                if (customer_queue[j] > customer_queue[j + 1]) {
                    string temp = customer_queue[j];
                    customer_queue[j] = customer_queue[j + 1];
                    customer_queue[j + 1] = temp;
                }
            }
        }
        cout << "Queue sorted alphabetically." << endl;
    } else {
        cout << "Queue is empty, nothing to sort." << endl;
    }
}


bool insert_at_position(string customer_name, int pos) {
    if (queue_size >= MAX_SIZE) {
        cout << "Queue is full! Cannot insert.\n";
        return false;
    }
    if (pos < 0 || pos > queue_size) {
        cout << "Invalid position!\n";
        return false;
    }

    for (int i = queue_size; i > pos; i--) {
        customer_queue[i] = customer_queue[i - 1];
    }

    customer_queue[pos] = customer_name;
    queue_size++;
    return true;
}



int main() {
    string user_choice;
    do {
        showMenu();
        cin >> user_choice;

        if (user_choice == "1") {
            string new_customer;
            cout << "Enter customer name: ";
            cin >> new_customer;
            add_customer(new_customer);
        } else if (user_choice == "2") {
            serve_next_customer();
        } else if (user_choice == "3") {
            string target_customer;
            cout << "Enter customer name you want to find: ";
            cin >> target_customer;
            int pos = find_customer(target_customer);

            if (pos != -1) {
                cout << "Customer " << target_customer
                     << " found at position " << (pos + 1) << "." << endl;
            } else {
                cout << "Customer " << target_customer << " not found in queue." << endl;
            }
        } else if(user_choice == "4") {
            sort_queue();
        } else if (user_choice == "6") {
            string new_customer;
            int pos;
            cout << "Enter customer name: ";
            cin >> new_customer;
            cout << "Enter position (1 to " << (queue_size + 1) << "): ";
            cin >> pos;

            if (insert_at_position(new_customer, pos - 1)) {
                cout << "Customer inserted successfully.\n";
            }
        } else if (user_choice == "0") {
            cout << "Exiting system..." << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    } while (user_choice != "0");

    return 0;
}
