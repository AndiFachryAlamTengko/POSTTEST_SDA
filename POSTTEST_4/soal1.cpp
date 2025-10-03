#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// fungsi untuk menambahkan data ke atas stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// fungsi untuk mengambil data dari atas stack
char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

// fungsi untuk membalik string dengan stack
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // setiap huruf dimasukkan ke stack
    for (char c : s) {
        push(stackTop, c);
    }

    // keluarkan dari stack untuk membalik urutan
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli   : " << text << endl;
    cout << "Teks balik  : " << reverseString(text) << endl;
    return 0;
}
