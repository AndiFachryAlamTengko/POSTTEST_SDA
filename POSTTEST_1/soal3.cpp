#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

bool banding(const Mahasiswa &a, const Mahasiswa &b) {
    return a.ipk < b.ipk;
}

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    sort(mhs, mhs + N, banding);

    cout << "\nData Mahasiswa (IPK ascending):\n";
    for (auto &m : mhs) {
        cout << m.nama << " - " << m.nim << " - " << m.ipk << endl;
    }
}