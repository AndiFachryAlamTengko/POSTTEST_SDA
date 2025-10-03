#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

// fungsi untuk cek keseimbangan tanda kurung
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    for (char c : expr) {
        // kalau kurung buka masuk ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // kalau kurung tutup cek pasangannya
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false;
            char topChar = pop(stackTop);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    // kalau stack kosong berarti seimbang
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    return 0;
}
