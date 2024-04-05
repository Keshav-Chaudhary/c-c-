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

    // Private helper method to find and delete a node from the BST
    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node found, handle deletion based on number of children
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node has two children, find the inorder successor (smallest node in right subtree)
            TreeNode* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }

        return node;
    }

    // Private helper method to find the smallest node (leftmost node) in a subtree
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Private helper method for inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left); // Traverse left subtree
            cout << node->key << " "; // Print current node
            inorderTraversal(node->right); // Traverse right subtree
        }
    }

public:
    BST() {
        root = nullptr;
    }

    // Public method to insert a new key into the BST
    void insert(int key) {
        root = insertNode(root, key);
    }

    // Public method to remove a key from the BST
    void remove(int key) {
        root = deleteNode(root, key);
    }

    // Public method to perform inorder traversal of the BST
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

// Main function to test the BST implementation
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    bst.remove(20);
    bst.remove(30);

    cout << "Inorder traversal after deletion: ";
    bst.inorder();

    return 0;
}
