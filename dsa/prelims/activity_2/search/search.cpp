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

    string valueToSearch = "OOP";
    int indexValue = -1;

    // Search
    for (int i = 0; i < lengthOfArray; i++) {
        if (compScieSubjects[i] == valueToSearch) {
            indexValue = i;
            break;
        }
    }

    if (indexValue != -1)
        cout << "Found at index: " << indexValue;
    else
        cout << "Value not found";
}
