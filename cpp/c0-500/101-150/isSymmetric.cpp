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
    // Helper function to check if two trees are mirrors of each other
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true; // Both nodes are null, they are mirrors
        if (!t1 || !t2) return false; // One is null, the other is not, not mirrors
        return (t1->val == t2->val) &&  // Check values are equal
               isMirror(t1->left, t2->right) &&  // Check left of t1 with right of t2
               isMirror(t1->right, t2->left);  // Check right of t1 with left of t2
    }
    
    // Function to check if a tree is symmetric
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root); // Check if tree is a mirror of itself
    }
};

int main() {
    // Example test case
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    Solution sol;
    cout << (sol.isSymmetric(root) ? "true" : "false") << endl; // Output the result
    
    return 0;
}
