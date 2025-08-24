#include <iostream>
#include <string>

int main() {
    int max_items = 10;
    int current_length = 3;
    std::string items[max_items];

    std::cout << "Enter 3 grocery items:\n";
    for (int i=0; i<current_length; i++) {
        std::string new_value;
        std::cout << "Item " << i+1 << ": ";
        std::cin >> new_value;
        items[i] = new_value;
    }

    char choice = '0';

    while(choice!='3') {
        std::cout << "Menu:\n";
        std::cout << "1. Add an item\n";
        std::cout << "2. Show grocery list\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        if (choice == '1') {
            if (current_length >= max_items) {
                std::cout << "\nCannot add anymore";
            } else {
                std::string new_grocery;
                std::cout << "\nEnter grocery item to add: ";
                std::cin >> new_grocery;
                items[current_length] = new_grocery;
                current_length++;
            }

        } else if (choice == '2') {
            std:: cout << "\n";
            for (int j = 0; j<current_length; j++) {
                std::cout << items[j] << "\n";
            }
        } else if (choice == '3') {
            std:: cout << "\n";
            std::cout << "exiting.";
            break;
        } else {
            std::cout << "\n";
            std::cout << "please enter a proper choice.";
        }
    }
}
