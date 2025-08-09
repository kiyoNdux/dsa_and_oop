#include <iostream>
using namespace std;

int main()
{
    const int maxSize = 10;
    int lengthOfArray = 4; // currently used elements

    // Array Initialization
    string compScieSubjects[maxSize] = {
        "Linear Algebra",
        "Probability",
        "Data Structures and Algorithms",
        "OOP"
    };

    int indexToInsert = 1;
    string valueToInsert = "Machine Learning";


    cout << "Before Array: ";
    for (int i = 0; i < lengthOfArray; ++i) {
        cout << compScieSubjects[i] << " ";
    }

    // Bounds checks
    if (indexToInsert < 0 || indexToInsert > lengthOfArray) {
        cout << "\nInvalid index\n";
        return 0;
    }
    if (lengthOfArray >= maxSize) {
        cout << "\nIndex out of Bounds\n";
        return 0;
    }

    // Shift right to make room (start from last used index)
    for (int j = lengthOfArray; j > indexToInsert; --j) {
        compScieSubjects[j] = compScieSubjects[j - 1];
    }

    // Insert and update length
    compScieSubjects[indexToInsert] = valueToInsert;
    ++lengthOfArray;

    cout << "\nAfter: ";
    for (int i = 0; i < lengthOfArray; ++i) cout << compScieSubjects[i] << " ";

    return 0;
}
