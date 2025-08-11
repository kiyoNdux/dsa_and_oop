#include <iostream>
using namespace std;

int main() {

    const int lengthOfArray = 4;

    string compScieSubjects[lengthOfArray] = {
        "Linear Algebra",
        "Probability",
        "Data Structures and Algorithms",
        "OOP"
    };

    int indexToReplace = 0; // Replace first element
    string newValue = "Machine Learning";

    // Before Array
    cout << "Before Array: ";
    for (int i = 0; i < lengthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }

    // Replace
    compScieSubjects[indexToReplace] = newValue;

    // After Array
    cout << "\nAfter Array: ";
    for (int i = 0; i < lengthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }
}
