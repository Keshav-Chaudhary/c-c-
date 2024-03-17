/*Implement stack and queue from scratch using pointers in C++. 
They should have all the functions supported by stacks and queues, e.g., insert, pop, top*/
#include <iostream>
using namespace std;
// Node structure for both stack and queue
template <typename T>
struct Node {
    T data;
    Node* next;
};
// Stack implementation using pointers
template <typename T>
class Stack {
private:
    Node<T>* topNode;
public:
    Stack() : topNode(nullptr) {}
    void push(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return topNode->data;
    }
    bool isEmpty() const {
        return topNode == nullptr;
    }
};
// Queue implementation using pointers
template <typename T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return frontNode->data;
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }
};
int main() {
    // Example usage of stack
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element of stack: " << stack.top() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;
    // Example usage of queue
    Queue<string> queue;
    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("!");
    cout << "Front element of queue: " << queue.front() << endl;
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl;

    return 0;
}
