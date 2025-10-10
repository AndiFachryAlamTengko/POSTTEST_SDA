#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor untuk membuat node baru
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambah node ke dalam BST
Node* insert(Node* root, int val) {
    // Jika belum ada root, buat node baru
    if (root == nullptr) {
        return new Node(val);
    }
    // Jika nilai lebih kecil, masuk ke subtree kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Jika nilai lebih besar, masuk ke subtree kanan
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    // Kembalikan root utama
    return root;
}

// Fungsi menghitung jumlah total node dalam tree
int countNodes(Node* root) {
    // Jika tree kosong (tidak ada node)
    if (root == nullptr)
        return 0;

    // Hitung 1 node sekarang + semua node di kiri + semua node di kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    // Tambah data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    // Cetak hasil total node
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; 
    // Output seharusnya 4
    return 0;
}
