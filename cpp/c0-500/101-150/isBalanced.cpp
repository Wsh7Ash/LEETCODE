#include <iostream>
#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;  // If the return value is -1, the tree is not balanced.
    }

private:
    // Helper function to check balance and calculate height
    int checkBalance(TreeNode* root) {
        if (!root) return 0;  // An empty tree has height 0 and is balanced.

        // Recursively check the left and right subtrees
        int leftHeight = checkBalance(root->left);
        int rightHeight = checkBalance(root->right);

        // If either subtree is unbalanced (indicated by -1), propagate failure upwards
        if (leftHeight == -1 || rightHeight == -1) return -1;

        // If the difference in heights is greater than 1, the tree is unbalanced
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Return the height of the current node's subtree
        return max(leftHeight, rightHeight) + 1;
    }
};

// Helper function to create a tree (for testing purposes)
TreeNode* createTree() {
    // Example: Creating the tree from the first example: [3, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    
    // Test case: Balanced tree
    TreeNode* root1 = createTree();
    cout << "Is tree balanced? " << (sol.isBalanced(root1) ? "true" : "false") << endl;

    // Test case: Unbalanced tree (you can create an unbalanced tree similarly)
    // Tree structure: [1, 2, 2, 3, 3, null, null, 4, 4]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);
    cout << "Is tree balanced? " << (sol.isBalanced(root2) ? "true" : "false") << endl;

    return 0;
}
