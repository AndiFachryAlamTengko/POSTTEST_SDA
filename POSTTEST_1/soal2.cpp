#include <iostream>
using namespace std;

int main() {
    int M[3][3];
    int nilai = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            M[i][j] = nilai++;
        }
    }

    cout << "Matriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    int total = 0;
    for (int i = 1; i < 3; i += 2) {
        for (int j = 0; j < 3; j++) {
            total += M[i][j];
        }
    }

    cout << "Jumlah baris genap = " << total << endl;
}