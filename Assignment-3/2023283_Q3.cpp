// Include necessary libs.
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Defining a structure for a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Func. to check if two nodes are at the same level and have different parents or not ?
bool isValidTeam(TreeNode* root, int node1, int node2) {
    if (!root) return false;

    unordered_map<int, int> parent;  // Map to store parent nodes
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                parent[node->left->val] = node->val;  // Storing parent of left child
            }
            if (node->right) {
                q.push(node->right);
                parent[node->right->val] = node->val;  // Storing parent of right child
            }
        }
    }

    if (parent.find(node1) != parent.end() && parent.find(node2) != parent.end()) {
        int parent1 = parent[node1];
        int parent2 = parent[node2];
        return parent1 != parent2;  // returning true if different parents
    }

    return false;  // if None or One or both nodes not found
}

int main() {
    // Creating the binary tree
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(13);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(14);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(24);
    root->left->left->left = new TreeNode(22);
    root->left->left->right = new TreeNode(23);

    // Queries to check team validity as per the given test case in this question 
    cout << "Query 1: 24 and 22" << endl;
    cout << "Output 1: " << (isValidTeam(root, 24, 22) ? "Yes" : "No") << endl;

    cout << "Query 2: 14 and 15" << endl;
    cout << "Output 2: " << (isValidTeam(root, 14, 15) ? "Yes" : "No") << endl;

    return 0;
}
