#include <iostream>
using namespace std;

int main()
{
    // Input List Data
    const int listaSize = 3;
    const int listbSize = 2;

    int lista[listaSize] = {1, 2, 3};
    int listb[listbSize] = {4, 5};

    // Result Array
    int newList[listaSize + listbSize];


    // -------- Catenate --------
    // Copy lista into newList
    for (int i = 0; i < listaSize; i++) {
        newList[i] = lista[i];
    }
    // Append listb to newList
    for (int j = 0; j < listbSize; j++) {
        newList[listaSize + j] = listb[j];
    }

    cout << "\nCatenated Array: ";
    for (int k = 0; k < (listaSize + listbSize); k++) {
        cout << newList[k] << " ";
    }
}
