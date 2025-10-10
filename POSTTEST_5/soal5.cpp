#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor untuk inisialisasi node baru
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun BST
Node* insert(Node* root, int val) {
    // Jika belum ada root, buat node baru
    if (root == nullptr) {
        return new Node(val);
    }
    // Jika lebih kecil, masuk ke kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Jika lebih besar, masuk ke kanan
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi traversal pre-order (root, kiri, kanan)
void preOrderTraversal(Node* root) {
    // Jika tree kosong, langsung keluar
    if (root == nullptr)
        return;

    // Cetak data root terlebih dahulu
    cout << root->data << " ";
    // Lanjutkan ke subtree kiri
    preOrderTraversal(root->left);
    // Terakhir ke subtree kanan
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    // Tambah beberapa data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Cetak hasil traversal pre-order
    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); // Output: 50 30 20 40 70 60 80
    cout << endl;
    return 0;
}
