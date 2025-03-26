class Solution {
    public:
        bool isValidBST(TreeNode* root, long lower = LONG_MIN, long upper = LONG_MAX) {
            if (!root) return true; // Base case: empty tree is a valid BST
            
            // Check if current node's value is within the valid range
            if (root->val <= lower || root->val >= upper) {
                return false;
            }
            
            // Recursively check the left and right subtrees with updated bounds
            return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
        }
    };
    