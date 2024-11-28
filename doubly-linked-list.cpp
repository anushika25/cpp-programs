#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* create(int arr[], int n) {
    Node* head = nullptr, * last = nullptr;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node{ arr[i], nullptr, nullptr };
        if (!head) 
            head = last = temp;
        else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
    return head;
}

void insert(Node*& head, int value) {
    Node* temp = new Node{ value, nullptr, nullptr };
    if (!head) 
        head = temp;
    else {
        Node* curr = head;
        while (curr->next) 
            curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }
}

void del(Node*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head) 
            head->prev = nullptr;
        delete temp;
        return;
    }
    Node* curr = head;
    while (curr && curr->data != value) 
        curr = curr->next;
    if (curr) {
        if (curr->next) 
            curr->next->prev = curr->prev;
        if (curr->prev) 
            curr->prev->next = curr->next;
        delete curr;
    }
}

void traverse(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
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