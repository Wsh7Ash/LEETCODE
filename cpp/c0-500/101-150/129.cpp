class Solution {
    public:
        int sumNumbers(TreeNode* root, int currentSum = 0) {
            if (!root) return 0; // Base case: if the node is NULL, return 0
    
            currentSum = currentSum * 10 + root->val; // Form the number
    
            // If it's a leaf node, return the formed number
            if (!root->left && !root->right) return currentSum;
    
            // Recur for left and right subtrees
            return sumNumbers(root->left, currentSum) + sumNumbers(root->right, currentSum);
        }
    };
    