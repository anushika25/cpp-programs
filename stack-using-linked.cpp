#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

class StackLinkedList {
    Node* top;
public:
    StackLinkedList() : top(nullptr) {}
    void push(int value) { Node* temp = new Node{value, top}; top = temp; }
    void pop() { if (!top) cout << "Underflow\n"; else { Node* temp = top; top = top->next; delete temp; } }
    void display() { for (Node* temp = top; temp; temp = temp->next) cout << temp->data << " "; cout << endl; }
};

int main() {
    StackLinkedList s;
    s.push(10); s.push(20); s.push(30); s.display();
    s.pop(); s.display();
    return 0;
}