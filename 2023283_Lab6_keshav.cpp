#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int value;
    Node* next;
    
    Node(int value) : value(value), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void rightrotate(int k) {
        if (!head || !head->next || k == 0) {
            return;
        }

        int length = 1;
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        k %= length;

        if (k == 0) {
            return;
        }

        int tailpositionnew = length - k;
        Node* newTail = head;
        for (int i = 0; i < tailpositionnew - 1; i++) {
            newTail = newTail->next;
        }

        tail->next = head;
        head = newTail->next;
        newTail->next = nullptr;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->value;
            if (current->next) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout <<endl;
    }
};

int main() {
    LinkedList ll;
    vector<int> input = {1, 2, 3, 4, 5}; 
    int k = 2; 

    for (int val : input) {
        ll.add(val);
    }

    cout << "Original linked list:" << endl;
    ll.display();

    ll.rightrotate(k);

    cout << "after rotating to the right by " << k << " places:" << endl;
    ll.display();

    return 0;
}