#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi untuk menukar head dan tail
void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) return;

    Node* head = head_ref;
    Node* tail = head_ref->prev;

    // kalau hanya ada 2 node, cukup ganti head
    if (head->next == tail && tail->next == head) {
        head_ref = tail;
        return;
    }

    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // perbaiki pointer agar head dan tail tertukar
    headNext->prev = tail;
    tail->next = headNext;
    tail->prev = head->prev;
    head->prev->next = tail;

    tailPrev->next = head;
    head->prev = tailPrev;
    head->next = tail->next;
    tail->next->prev = head;

    head_ref = tail; // tail jadi head baru
}

// cetak isi list
void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// fungsi untuk menambah node di akhir
void insertEnd(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange: ";
    printList(head);

    return 0;
}
