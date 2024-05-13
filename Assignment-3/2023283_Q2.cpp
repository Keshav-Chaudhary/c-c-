#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// Define a structure for a tree node
struct Node {
    int data; // Data stored in the node
    bool unusable; // Flag indicating if the node has been processed
    Node* left; // Pointer to the left child
    Node* right; // ------------------- child
    Node* parent; // ------------------- node

    // Constructor to initialize the node
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), unusable(false) {}
};

class BinaryTree {
public:
    // Funct. to construct the binary tree from a vector of strings
    Node* constructTree(const vector<string>& arr, Node* parent, int i) {
        if (i >= arr.size() || arr[i] == "N") return nullptr; // Checking for empty nodes or "N"

        // Creating a new node with the int value from the str.
        Node* root = new Node(stoi(arr[i]));
        root->parent = parent; // Setting out the parent of the current node
        // Recursively construct left and right subtrees
        root->left = constructTree(arr, root, 2 * i + 1);
        root->right = constructTree(arr, root, 2 * i + 2);
        return root; // returning the constructed subtree
    }

    // Funct. to search for a target value in the binary tree
    Node* search(Node* root, int target) {
        if (!root) return nullptr; 
        queue<Node*> q; 
        q.push(root); // Pushing the root node into the queue

        // performing level-order traversal
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            // Checking if the current nodes data matches the target
            if (current->data == target) return current;
            // enqueuing left and right children if they exist
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        return nullptr; // returning nullptr if the target is not found
    }

    // funct. to performing explosion propagation from a target node
    vector<vector<int>> ExplosionPropagate(Node* target) {
        if (!target) return {}; // returning empty vector if target is null

        vector<vector<int>> results; 
        queue<Node*> q; 
        q.push(target); 
        target->unusable = true; 

        // performing agian level-order traversal for explosion propagation
        while (!q.empty()) {
            int size = q.size(); 
            vector<int> currentLevel; 
            for (int i = 0; i < size; ++i) {
                Node* node = q.front(); // Getting out the front node from the queue
                q.pop(); // Removing the front node from the queue

                currentLevel.push_back(node->data); // Add the node's data to the current level

                // Lambda function to enqueue child nodes if they exist and are not marked as unusable
                auto enqueueChild = [&q](Node* child) {
                    if (child && !child->unusable) {
                        q.push(child); // Enqueue the child node
                        child->unusable = true; // Mark the child node as unusable
                    }
                };

                // enqueueing left, right, and parent nodes of the current node
                enqueueChild(node->left);
                enqueueChild(node->right);
                enqueueChild(node->parent);
            }
            results.push_back(currentLevel); // Adding the current level to the results
        }
        return results; // return the explosion propagation results
    }
};

int main() {
    BinaryTree tree; // Creating an instance of the BinaryTree class

    // Input vector representing the binary tree in level-order traversal as given inn the qustion 
    vector<string> Tree = {"12", "13", "10", "N", "N", "14", "15", "N", "N", "N", "N", "21", "24", "22", "23"};
    // Construct the binary tree
    Node* root = tree.constructTree(Tree, nullptr, 0);

    // Search for the target node with data 14
    Node* target = tree.search(root, 14);
    if (!target) {
        cout << "Target not found in the tree." << endl;
        return 0;
    }

    // Perform explosion propagation from the target node
    vector<vector<int>> explosionResult = tree.ExplosionPropagate(target);

    // Output the blast sequence results
    cout << "Blast sequence results:" << endl;
    for (const auto& level : explosionResult) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
