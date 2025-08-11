#include <iostream>
using namespace std;

int main()
{
    // Array Sizes
    int listaSize = 3;
    int listbSize = 3;

    // Array Initialization
    int lista[listaSize] = {1, 2, 3};
    int listb[listbSize] = {4, 5, 6};

    // Resultant Array (Merged)
    int listc[listaSize + listbSize];

    int a = 0; // Index for lista
    int b = 0; // Index for listb
    int c = 0; // Index for listc

    // Merge
    while (a < listaSize && b < listbSize) {
        if (lista[a] < listb[b]) {
            listc[c] = lista[a];
            a++;
        } else {
            listc[c] = listb[b];
            b++;
        }
        c++;
    }

    // Copy Remaining Elements from lista
    while (a < listaSize) {
        listc[c] = lista[a];
        a++;
        c++;
    }

    // Copy Remaining Elements from listb
    while (b < listbSize) {
        listc[c] = listb[b];
        b++;
        c++;
    }

    cout << "\nMerged Array: ";
    for (int k = 0; k < (listaSize + listbSize); k++) {
        cout << listc[k] << " ";
    }
}
