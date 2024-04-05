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

    int calculateHeight(TreeNode* node) {
        if (node == nullptr) {
            return -1; // Height of an empty tree is considered -1
        }

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    int height() {
        return calculateHeight(root);
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

    cout << "Height of the BST: " << bst.height() << endl;

    return 0;
}
/*      50        -> level 0 (root)
      /    \
    30      70    -> level 1 (childrem of root)
   /  \    /  \
 20   40  60   80 -> level 2 (children of node level 1)

 */
