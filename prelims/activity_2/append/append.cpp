#include <iostream>
using namespace std;

int main() {
    const int maxSize = 10; // Max capacity
    int lengthOfArray = 4;  // Current number of elements

    string compScieSubjects[maxSize] = {
        "Linear Algebra",
        "Probability",
        "Data Structures and Algorithms",
        "OOP"
    };

    // Before Append
    cout << "Before Array: ";
    for (int i = 0; i < lengthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }

    // Append
    string newValue = "Calculus";
    if (lengthOfArray < maxSize) {
        compScieSubjects[lengthOfArray] = newValue;
        lengthOfArray++;
    }

    // After Append
    cout << "\nAfter Array: ";
    for (int i = 0; i < lengthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }
}
