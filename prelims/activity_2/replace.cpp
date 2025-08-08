#include <iostream>
using namespace std;

int main()
{
    // User input
    int userInputIndex = 0;
    string inputUserValue = "Machine Learning";

    // Initialize Array
    string compScieSubjects[4] = {"Linear Algebra", "Probability", "DataStructures and Algorithms", "OOP"};


    // Size of the Array
    int lenthOfArray = 4;


    // Before Array
    cout << "Before Array: ";
    for (int i=0; i<lenthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }

    // Replace
    compScieSubjects[userInputIndex] = inputUserValue;


    // After Array
    cout << "\nAfter Array: ";
    for (int i=0; i<lenthOfArray; i++) {
        cout << compScieSubjects[i] << " ";
    }

}
