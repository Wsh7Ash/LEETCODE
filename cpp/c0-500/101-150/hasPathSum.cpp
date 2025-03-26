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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // If tree is empty, return false
        
        // If it's a leaf node and the targetSum is met, return true
        if (!root->left && !root->right && targetSum == root->val) 
            return true;

        // Recursively check left and right subtree
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};

// Helper function to create the sample tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createTree();
    cout << "Has path sum (22): " << (sol.hasPathSum(root1, 22) ? "true" : "false") << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << "Has path sum (5): " << (sol.hasPathSum(root2, 5) ? "true" : "false") << endl;

    TreeNode* root3 = nullptr;
    cout << "Has path sum (0): " << (sol.hasPathSum(root3, 0) ? "true" : "false") << endl;

    return 0;
}
