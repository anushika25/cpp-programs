#include <iostream>
using namespace std;

class StackArray {
    int top, capacity, *stack;
public:
    StackArray(int size) : top(-1), capacity(size) { stack = new int[size]; }
    void push(int value) { if (top == capacity - 1) cout << "Overflow\n"; else stack[++top] = value; }
    void pop() { if (top == -1) cout << "Underflow\n"; else top--; }
    void display() { for (int i = top; i >= 0; i--) cout << stack[i] << " "; cout << endl; }
    ~StackArray() { delete[] stack; }
};

int main() {
    StackArray s(5);
    s.push(10); s.push(20); s.push(30); s.display();
    s.pop(); s.display();
    return 0;
}