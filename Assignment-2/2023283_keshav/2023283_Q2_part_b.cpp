/*Use your stack implementation from above and solve the following problem:-
Given a circular integer array nums (i.e., the next element of nums[nums.length -
1] is nums[0]), return the next greater number for every element in nums. The next
greater number of a number x is the first greater number to its traversing order
next in the array, which means you could search circularly to find its next greater
number.
Input: [1,2,3,4,3]
Output: [2,3,4,-1,4]*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cerr << "Stack underflow!" << endl;
            return;
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const {
        if (isEmpty()) {
            cerr << "Stack is empty!" << endl;
            return T();
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }
};

vector<int> nextGreaterElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    Stack<int> stack;

    for (int i = 0; i < 2 * n; ++i) {
        int index = i % n;
        while (!stack.isEmpty() && nums[index] > nums[stack.top()]) {
            result[stack.top()] = nums[index];
            stack.pop();
        }
        if (i < n) {
            stack.push(i);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> result = nextGreaterElements(nums);

    cout << "Input: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
