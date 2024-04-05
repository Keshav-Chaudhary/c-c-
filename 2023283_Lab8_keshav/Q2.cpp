#include <iostream>
using namespace std;

// TreeNode class represents nodes in the Binary Search Tree (BST)
class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node with a key value
    TreeNode(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

// BST class represents the Binary Search Tree data structure
class BST {
private:
    TreeNode* root;

    // Private helper method to insert a new node into the BST
    TreeNode* insertNode(TreeNode* node, int key) {
        // If the current node is null, create a new node with the given key
        if (node == nullptr) {
            return new TreeNode(key);
        }

        // Recursively insert into the left subtree if key is smaller
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        // Recursively insert into the right subtree if key is larger
        else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

public:
    // Constructor to initialize an empty BST
    BST() {
        root = nullptr;
    }

    // Public method to insert a new key into the BST
    void insert(int key) {
        root = insertNode(root, key);
    }

    // Private helper method for inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left); // Traverse left subtree
            cout << node->key << " "; // Print current node
            inorderTraversal(node->right); // Traverse right subtree
        }
    }

    // Public method to perform inorder traversal of the BST
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

// Main function to test the BST insertion operation
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal after insertion: ";
    bst.inorder(); // Output should be sorted: 20 30 40 50 60 70 80

    return 0;
}
