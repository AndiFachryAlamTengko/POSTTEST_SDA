#include <iostream>
using namespace std;

// Struktur node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun BST
Node* insert(Node* root, int val) {
    // Jika root kosong, buat node baru
    if (root == nullptr) {
        return new Node(val);
    }
    // Jika nilai lebih kecil, masuk subtree kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Jika nilai lebih besar, masuk subtree kanan
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi mencari nilai terbesar dalam BST
int findMaxValue(Node* root) {
    // Jika tree kosong
    if (root == nullptr)
        return -1;

    // Telusuri terus ke kanan karena nilai besar selalu di kanan
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    // Masukkan data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    // Cetak nilai terbesar
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    // Output seharusnya 80
    return 0;
}
