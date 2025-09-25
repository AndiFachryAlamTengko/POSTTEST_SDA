#include <iostream>
#include <string>
using namespace std;

struct Penerbangan {
    string kode;
    string tujuan;
    string status;
    Penerbangan *next;
    Penerbangan *prev;
};

Penerbangan *head = NULL;
Penerbangan *tail = NULL;
int panjangList = 0;

string nama, nim;
int urutanKode = 0;

// Buat kode penerbangan otomatis
string buatKode() {
    string dasar = "JT-006";
    if (urutanKode == 0) {
        urutanKode++;
        return dasar;
    } else {
        return dasar + "-" + to_string(urutanKode++);
    }
}

// Tambah di awal
void insertFirst(Penerbangan *&head, Penerbangan *&tail) {
    cout << "\n[ Tambah jadwal di awal ]" << endl;
    Penerbangan *baru = new Penerbangan();
    baru->kode = buatKode();
    cout << "Tujuan : "; cin.ignore(); getline(cin, baru->tujuan);
    baru->status = "Tepat Waktu";
    baru->prev = NULL;
    baru->next = head;

    if (head == NULL && tail == NULL) {
        head = tail = baru;
    } else {
        head->prev = baru;
        head = baru;
    }
    panjangList++;
    cout << ">> Jadwal berhasil ditambahkan dengan kode: " << baru->kode << endl;
}

// Tambah di akhir
void insertLast(Penerbangan *&head, Penerbangan *&tail) {
    cout << "\n[ Tambah jadwal di akhir ]" << endl;
    Penerbangan *baru = new Penerbangan();
    baru->kode = buatKode();
    cout << "Tujuan : "; cin.ignore(); getline(cin, baru->tujuan);
    baru->status = "Tepat Waktu";
    baru->prev = tail;
    baru->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    panjangList++;
    cout << ">> Jadwal berhasil ditambahkan dengan kode: " << baru->kode << endl;
}

// Tambah di posisi tertentu
void insertAt(Penerbangan *&head, Penerbangan *&tail, int posisi) {
    if (posisi < 1 || posisi > panjangList + 1) {
        cout << ">> Posisi tidak valid!" << endl;
        return;
    }
    if (posisi == 1) {
        insertFirst(head, tail);
    } else if (posisi == panjangList + 1) {
        insertLast(head, tail);
    } else {
        cout << "\n[ Tambah jadwal di posisi " << posisi << " ]" << endl;
        Penerbangan *baru = new Penerbangan();
        baru->kode = buatKode();
        cout << "Tujuan : "; cin.ignore(); getline(cin, baru->tujuan);
        baru->status = "Tepat Waktu";

        Penerbangan *temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }

        baru->next = temp->next;
        baru->prev = temp;
        temp->next->prev = baru;
        temp->next = baru;

        panjangList++;
        cout << ">> Jadwal berhasil ditambahkan dengan kode: " << baru->kode << endl;
    }
}

// Hapus awal
void deleteFirst(Penerbangan *&head, Penerbangan *&tail) {
    if (head == NULL && tail == NULL) {
        cout << ">> Linked List kosong" << endl;
    } else if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        panjangList--;
        cout << ">> Jadwal berhasil dihapus." << endl;
    } else {
        Penerbangan *del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
        panjangList--;
        cout << ">> Jadwal berhasil dihapus." << endl;
    }
}

// Ubah status
void ubahStatus() {
    if (head == NULL) {
        cout << ">> Tidak ada jadwal." << endl;
        return;
    }
    string cari;
    cout << "Masukkan kode penerbangan: ";
    cin >> cari;

    Penerbangan *temp = head;
    while (temp != NULL) {
        if (temp->kode == cari) {
            cout << "Status saat ini: " << temp->status << endl;
            cout << "Status baru: "; cin.ignore(); getline(cin, temp->status);
            cout << ">> Status berhasil diperbarui!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << ">> Jadwal tidak ditemukan." << endl;
}

// Tampilkan dari depan
void printList(Penerbangan *head) {
    if (head == NULL) {
        cout << ">> Linked List kosong" << endl;
        return;
    }
    cout << "\n=== DAFTAR JADWAL (DEPAN) ===" << endl;
    int i = 1;
    while (head != NULL) {
        cout << i++ << ". Kode: " << head->kode
             << " | Tujuan: " << head->tujuan
             << " | Status: " << head->status << endl;
        head = head->next;
    }
}

// Tampilkan dari belakang
void printReverse(Penerbangan *tail) {
    if (tail == NULL) {
        cout << ">> Linked List kosong" << endl;
        return;
    }
    cout << "\n=== DAFTAR JADWAL (BELAKANG) ===" << endl;
    int i = panjangList;
    while (tail != NULL) {
        cout << i-- << ". Kode: " << tail->kode
             << " | Tujuan: " << tail->tujuan
             << " | Status: " << tail->status << endl;
        tail = tail->prev;
    }
}

// Cari detail
void cariDetail() {
    if (head == NULL) {
        cout << ">> Linked List kosong" << endl;
        return;
    }
    string key;
    cout << "Masukkan Kode atau Tujuan: "; cin.ignore(); getline(cin, key);

    Penerbangan *temp = head;
    while (temp != NULL) {
        if (temp->kode == key || temp->tujuan == key) {
            cout << "\n=== DETAIL JADWAL ===" << endl;
            cout << "Kode   : " << temp->kode << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            return;
        }
        temp = temp->next;
    }
    cout << ">> Data tidak ditemukan." << endl;
}

int main() {
    cout << "Masukkan Nama: "; getline(cin, nama);
    cout << "Masukkan NIM : "; getline(cin, nim);

    int pilih, posisi;
    do {
        cout << "\n=============================================\n";
        cout << "   FLIGHT SCHEDULE MANAGEMENT (DLL)          \n";
        cout << "---------------------------------------------\n";
        cout << "Nama : " << nama << "\n";
        cout << "NIM  : " << nim  << "\n";
        cout << "=============================================\n";
        cout << "1. Tambah Jadwal di Awal\n";
        cout << "2. Tambah Jadwal di Akhir\n";
        cout << "3. Tambah Jadwal di Posisi Tertentu\n";
        cout << "4. Hapus Jadwal Pertama\n";
        cout << "5. Ubah Status Jadwal\n";
        cout << "6. Lihat Semua Jadwal (Depan)\n";
        cout << "7. Lihat Semua Jadwal (Belakang)\n";
        cout << "8. Cari Detail Jadwal\n";
        cout << "0. Keluar\n";
        cout << "=============================================\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1: insertFirst(head, tail); break;
            case 2: insertLast(head, tail); break;
            case 3: 
                cout << "Masukkan posisi: "; cin >> posisi;
                insertAt(head, tail, posisi); break;
            case 4: deleteFirst(head, tail); break;
            case 5: ubahStatus(); break;
            case 6: printList(head); break;
            case 7: printReverse(tail); break;
            case 8: cariDetail(); break;
            case 0: cout << "Keluar dari program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 0);

    return 0;
}
