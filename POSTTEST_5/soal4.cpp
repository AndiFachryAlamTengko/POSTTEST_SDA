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

// Fungsi insert untuk membangun BST
Node* insert(Node* root, int val) {
    // Jika tree masih kosong, buat node baru
    if (root == nullptr) {
        return new Node(val);
    }
    // Masuk ke kiri kalau lebih kecil
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Masuk ke kanan kalau lebih besar
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi untuk traversal post-order (kiri, kanan, root)
void postOrderTraversal(Node* root) {
    // Jika kosong, hentikan
    if (root == nullptr)
        return;

    // Kunjungi subtree kiri
    postOrderTraversal(root->left);
    // Kunjungi subtree kanan
    postOrderTraversal(root->right);
    // Cetak node sekarang (root)
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    // Buat tree dengan beberapa data
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Cetak hasil traversal post-order
    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // Hasil: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}
