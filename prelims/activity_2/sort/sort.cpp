#include <iostream>
using namespace std;

int main()
{
    const int maxSize = 20;
    int lengthOfArray = 10; // currently used elements

    // Array Initialization
    int compScieSubjects[maxSize] = {3, 2, 5, 6, 3, 7, 8, 10, 9};


    // Before Sorting
    cout << "\nBefore Array: ";
    for (int k = 0; k < lengthOfArray; k++) {
        cout << compScieSubjects[k] << " ";
    }

    for (int i=0; i<lengthOfArray; i++) {
            for (int j=0; j<lengthOfArray - 1; j++) {
                if (compScieSubjects[j] > compScieSubjects[j+1]) {
                    // Swap Values
                    int temp = compScieSubjects[j];
                    compScieSubjects[j] = compScieSubjects[j + 1];
                    compScieSubjects[j + 1] = temp;                }
            }
    }

    // After Sorting
    cout << "\nAfter Array: ";
    for (int k = 0; k < lengthOfArray; k++) {
        cout << compScieSubjects[k] << " ";
    }
}
