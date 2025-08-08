#include <iostream>
using namespace std;

int main()
{
    // User input
    int userInputIndex = 1;
    string inputUserValue = "Machine Learning";

    // Size of the Array
    int lenthOfArray = 4;

    // Initialize Array
    string compScieSubjects[lenthOfArray] = {"Linear Algebra", "Probability", "DataStructures and Algorithms", "OOP"};

    // Before Array
    cout << "Before Array: ";
    for (int i=0; i<lenthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }

    for (int i=0; i<=lenthOfArray; i++) {
        if (i == userInputIndex) {
            lenthOfArray = lenthOfArray + 1;
            for (int j=i; j<=lenthOfArray; j++) {
                compScieSubjects[j-1] = compScieSubjects[j];
            }
            break;
        }
    }

    // After Array
    cout << "\nAfter Array: ";
    for (int i=0; i<lenthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }
}
