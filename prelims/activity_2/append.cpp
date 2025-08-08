#include <iostream>
using namespace std;

int main()
{

    // Size of the Array
    int lenthOfArray = 3;

    // Initialize Array
    string compScieSubjects[lenthOfArray] = {"Linear Algebra", "Probability", "DataStructures and Algorithms", "OOP"};

    // Before Array
    cout << "Before Array: ";
    for (int i=0; i<lenthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }

    string inputUserValue = "Calculus";

    // Append
    for (int i=0; i<=lenthOfArray; i++) {
        if (i == lenthOfArray) {
            lenthOfArray = lenthOfArray + 1;
            compScieSubjects[lenthOfArray] = inputUserValue;
            break;
        }
    }

    // After Array
    cout << "\nAfter Array: ";
    for (int i=0; i<lenthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }


}
