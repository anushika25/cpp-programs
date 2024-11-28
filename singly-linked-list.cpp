#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create(int arr[], int n) {
    Node* head = nullptr, * temp = nullptr, * last = nullptr;
    for (int i = 0; i < n; i++) {
        temp = new Node{ arr[i], nullptr };
        if (!head) 
            head = last = temp;
        else {
            last->next = temp;
            last = temp;
        }
    }
    return head;
}

void insert(Node*& head, int value) {
    Node* temp = new Node{ value, nullptr };
    if (!head) 
        head = temp;
    else {
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = temp;
    }
}

void del(Node*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    while (curr->next && curr->next->data != value)
        curr = curr->next;
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
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

    cout << "Original List: ";
    traverse(head);

    insert(head, 6); 
    cout << "After Insertion: ";
    traverse(head);

    del(head, 3);  
    cout << "After Deletion: ";
    traverse(head);

    return 0;
}