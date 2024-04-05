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

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            cout << node->key << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->key << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(root);
        cout << endl;
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

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    return 0;
}
