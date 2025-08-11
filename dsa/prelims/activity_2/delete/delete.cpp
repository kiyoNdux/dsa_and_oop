#include <iostream>
using namespace std;

int main()
{
    const int maxSize = 10;
    int lengthOfArray = 4;

    // Array Initialization
    string compScieSubjects[maxSize] = {
        "Linear Algebra",
        "Probability",
        "Data Structures and Algorithms",
        "OOP"
    };

    cout << "Before Array: ";
    for (int i = 0; i < lengthOfArray; ++i) {
        cout << compScieSubjects[i] << " ";
    }

    string valueToDelete = "Data Structures and Algorithms";

    // Find the index of valueToDelete
    int indexOftheValueToDelete = 0;
    for (int i = 0; i < lengthOfArray; ++i) {
        indexOftheValueToDelete = i; // Assign the correct index or valueToDelete
        if (compScieSubjects[i] == valueToDelete) {
            break;
        }
    }

    // Shifting element to the left
    for (int i = indexOftheValueToDelete; i < lengthOfArray - 1; ++i) {
        compScieSubjects[i] = compScieSubjects[i + 1]; // Shift the next element to the current element
    }

    // Will Decrement the array after shifting
    --lengthOfArray;

    cout << "\nAfter: ";
    for (int i = 0; i < lengthOfArray; ++i) {
        cout << compScieSubjects[i] << " ";
    }
}
