#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // Base case: empty tree has depth 0
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); // Recursively find max depth
    }
};

// Test case
int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Maximum Depth: " << depth << endl; // Expected Output: 3

    return 0;
}
