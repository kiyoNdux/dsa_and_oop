# include <iostream>
using namespace std;

void displayArray(int arr[], int arrSize) {
    cout << "Array contents: ";
    for (int i=0; i<arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void getValue(int arr[], int arrSize, int index) {
    if (index >= 0 && index < arrSize) {
        cout << "Value at index " << index << " is: " << arr[index] << endl;
    } else {
        cout << "Index out of range!" << endl;
    }
}

void replaceValue(int arr[], int arrSize, int index, int newValue) {
    if (index >= 0 && index < arrSize) {
        arr[index] = newValue;
        cout << "Value replaced." << endl;
    } else {
        cout << "Index out of range!" << endl;
    }
}

void appendValue(int arr[], int &arrSize, int newValue) {
    arr[arrSize] = newValue;
    arrSize ++;
    cout << "Value" << newValue << "Appended." << endl;
}

void insertValue(int arr[], int &arrSize, int index, int newValue) {
    if (index >= 0 && index <= arrSize) {
        for (int i=arrSize; i>index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = newValue;
        arrSize++;
        cout << "Value inserted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void deleteValue(int arr[], int &arrSize, int index) {
    if (index >= 0 && index < arrSize) {
        for (int i = index; i < arrSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arrSize--;
        cout << "Value deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}


int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int arrSize = 5;

    displayArray(arr, arrSize);
    getValue(arr, arrSize, 2);
    replaceValue(arr, arrSize, 2, 3000);
    displayArray(arr, arrSize);
    appendValue(arr, arrSize, 123);
    displayArray(arr, arrSize);
    insertValue(arr, arrSize, 4, 321);
    displayArray(arr, arrSize);
    deleteValue(arr, arrSize, 2);
    displayArray(arr, arrSize);

    return 0;
}
