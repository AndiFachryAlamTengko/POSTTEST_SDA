#include <iostream>
using namespace std;

// Struktur node untuk BST
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

// Fungsi untuk memasukkan nilai ke tree (insert BST)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi untuk mencari nilai terkecil
int findMinValue(Node* root) {
    // Jika tree kosong
    if (root == nullptr)
        return -1;

    // Selama masih ada anak kiri, terus jalan ke kiri
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    // Node paling kiri punya nilai terkecil
    return current->data;
}

int main() {
    Node* root = nullptr;
    // Tambahkan beberapa data ke tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    // Cetak nilai terkecil
    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;
    // Output seharusnya 20
    return 0;
}
