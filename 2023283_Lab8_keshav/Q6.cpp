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

    int countNodes(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        // Count the nodes in the left subtree + 1 (current node) + nodes in the right subtree
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    int nodeCount() {
        return countNodes(root);
    }

private:
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

    cout << "Number of nodes in the BST: " << bst.nodeCount() << endl;

    return 0;
}
