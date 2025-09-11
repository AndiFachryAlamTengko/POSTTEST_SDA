#include <iostream>
using namespace std;

bool cekPrima(int angka) {
    if (angka <= 1) return false;
    for (int i = 2; i * i <= angka; i++) {
        if (angka % i == 0) return false;
    }
    return true;
}

void balik(int *data, int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = *(data + i);
        *(data + i) = *(data + (n - 1 - i));
        *(data + (n - 1 - i)) = tmp;
    }
}

int main() {
    const int N = 7;
    int arr[N];
    int x = 2, count = 0;

    while (count < N) {
        if (cekPrima(x)) {
            arr[count++] = x;
        }
        x++;
    }

    cout << "Sebelum dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << "\n";

    balik(arr, N);

    cout << "Sesudah dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << "\n";
}
