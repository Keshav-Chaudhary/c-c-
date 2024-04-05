#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal before deletion: ";
    bst.inorder();

    bst.remove(20); // Node with no children
    bst.remove(30); // Node with one child
    bst.remove(70); // Node with two children

    cout << "Inorder traversal after deletion: ";
    bst.inorder();

    return 0;
}
