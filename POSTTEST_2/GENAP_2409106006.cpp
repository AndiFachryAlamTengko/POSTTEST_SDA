#include <iostream>
#include <string>
using namespace std;

// Struktur untuk node linked list
struct Penerbangan {
    string kode;
    string tujuan;
    string status;
    Penerbangan* next;
};

// Pointer head list
Penerbangan* head = NULL;

// Variabel global identitas
string nama, nim;
int urutanKode = 0;

// Fungsi pembuat kode penerbangan (selalu JT-006)
string buatKode() {
    string dasar = "JT-006";
    if (urutanKode == 0) {
        urutanKode++;
        return dasar;
    } else {
        return dasar + "-" + to_string(urutanKode++);
    }
}

// Menambah jadwal penerbangan di akhir list
void tambahJadwal() {
    Penerbangan* baru = new Penerbangan;
    baru->kode = buatKode();
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, baru->tujuan);
    baru->status = "Tepat Waktu";
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Penerbangan* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    cout << ">> Jadwal ditambahkan dengan kode: " << baru->kode << endl;
}

// Menyisipkan jadwal di posisi tertentu (digit terakhir NIM + 1)
void sisipJadwal() {
    int posisi = (nim.back() - '0') + 1;
    Penerbangan* baru = new Penerbangan;
    baru->kode = buatKode();
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, baru->tujuan);
    baru->status = "Tepat Waktu";
    baru->next = NULL;

    if (head == NULL || posisi <= 1) {
        baru->next = head;
        head = baru;
    } else {
        Penerbangan* bantu = head;
        for (int i = 1; i < posisi - 1 && bantu->next != NULL; i++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
    cout << ">> Jadwal berhasil disisipkan di posisi " << posisi 
         << " dengan kode: " << baru->kode << endl;
}

// Menghapus jadwal paling awal
void hapusAwal() {
    if (head == NULL) {
        cout << ">> Tidak ada jadwal yang bisa dihapus." << endl;
        return;
    }
    Penerbangan* hapus = head;
    head = head->next;
    cout << ">> Jadwal dengan kode " << hapus->kode << " dihapus." << endl;
    delete hapus;
}

// Update status penerbangan berdasarkan kode
void ubahStatus() {
    if (head == NULL) {
        cout << ">> Belum ada jadwal." << endl;
        return;
    }
    string cari;
    cout << "Masukkan kode penerbangan yang ingin diubah: ";
    cin >> cari;

    Penerbangan* bantu = head;
    while (bantu != NULL) {
        if (bantu->kode == cari) {
            cout << "Status saat ini: " << bantu->status << endl;
            cout << "Masukkan status baru: ";
            cin.ignore();
            getline(cin, bantu->status);
            cout << ">> Status berhasil diperbarui!" << endl;
            return;
        }
        bantu = bantu->next;
    }
    cout << ">> Kode penerbangan tidak ditemukan." << endl;
}

// Menampilkan semua jadwal penerbangan
void tampilkan() {
    if (head == NULL) {
        cout << ">> Tidak ada jadwal penerbangan." << endl;
        return;
    }
    cout << "\n=== DAFTAR JADWAL PENERBANGAN ===" << endl;
    Penerbangan* bantu = head;
    while (bantu != NULL) {
        cout << "Kode: " << bantu->kode
             << " | Tujuan: " << bantu->tujuan
             << " | Status: " << bantu->status << endl;
        bantu = bantu->next;
    }
}

// Program utama
int main() {
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    int pilih;
        do {
            cout << "\n=============================================\n";
            cout << "         FLIGHT SCHEDULE MANAGEMENT          \n";
            cout << "---------------------------------------------\n";
            cout << "Nama : " << nama << "\n";
            cout << "NIM  : " << nim  << "\n";
            cout << "=============================================\n";
            cout << ">> 1. Tambah Jadwal Penerbangan\n";
            cout << ">> 2. Sisipkan Jadwal Penerbangan\n";
            cout << ">> 3. Hapus Jadwal Pertama\n";
            cout << ">> 4. Ubah Status Penerbangan\n";
            cout << ">> 5. Lihat Semua Jadwal\n";
            cout << ">> 0. Keluar Program\n";
            cout << "=============================================\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> pilih;
        

        switch (pilih) {
            case 1: tambahJadwal(); break;
            case 2: sisipJadwal(); break;
            case 3: hapusAwal(); break;
            case 4: ubahStatus(); break;
            case 5: tampilkan(); break;
            case 0: cout << "Keluar dari program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 0);

    return 0;
}