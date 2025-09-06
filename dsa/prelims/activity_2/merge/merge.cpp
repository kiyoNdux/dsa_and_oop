#include <iostream>
using namespace std;

int main() {
    int lista[] = {1, 2, 3, 4, 5};
    int listb[] = {3, 4, 5, 6, 7};
    int listaSize = 5, listbSize = 5;

    int listc[listaSize + listbSize];
    int a = 0, b = 0, c = 0;

    while (a < listaSize && b < listbSize) {
        if (lista[a] < listb[b]) {
            if (c == 0 || listc[c-1] != lista[a]) // avoid duplicates
                listc[c++] = lista[a];
            a++;
        }
        else if (listb[b] < lista[a]) {
            if (c == 0 || listc[c-1] != listb[b])
                listc[c++] = listb[b];
            b++;
        }
        else { // equal values, add only once
            if (c == 0 || listc[c-1] != lista[a])
                listc[c++] = lista[a];
            a++;
            b++;
        }
    }

    while (a < listaSize) {
        if (c == 0 || listc[c-1] != lista[a])
            listc[c++] = lista[a];
        a++;
    }

    while (b < listbSize) {
        if (c == 0 || listc[c-1] != listb[b])
            listc[c++] = listb[b];
        b++;
    }

    cout << "Merged array: ";
    for (int k = 0; k < c; k++) {
        cout << listc[k] << " ";
    }
    cout << endl;

    return 0;
}
