#include <iostream>
using namespace std;

void tukarNilai(int &x, int &y) {
    int simpan = x;
    x = y;
    y = simpan;
}

int main() {
    int a, b;
    cout << "Masukkan dua bilangan: ";
    cin >> a >> b;

    cout << "Sebelum: a=" << a << ", b=" << b << endl;
    tukarNilai(a, b);
    cout << "Sesudah: a=" << a << ", b=" << b << endl;
}