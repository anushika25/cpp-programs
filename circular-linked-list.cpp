#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create(int arr[], int n) {
    Node* head = nullptr, * last = nullptr;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node{ arr[i], nullptr };
        if (!head) {
            head = last = temp;
            last->next = head;
        } else {
            last->next = temp;
            last = temp;
            last->next = head;
        }
    }
    return head;
}

void insert(Node*& head, int value) {
    Node* temp = new Node{ value, nullptr };
    if (!head) {
        head = temp;
        head->next = head;
    } else {
        Node* curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
    }
}

void del(Node*& head, int value) {
    if (!head) return;
    if (head->data == value && head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node *curr = head, *prev = nullptr;
    while (curr->data != value) {
        if (curr->next == head) return;
        prev = curr;
        curr = curr->next;
    }
    if (curr == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = head->next;
        prev->next = head;
    } else {
        prev->next = curr->next;
    }
    delete curr;
}

void traverse(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = create(arr, 5);
    traverse(head);
    insert(head, 6);
    traverse(head);
    del(head, 3);
    traverse(head);
    return 0;
}