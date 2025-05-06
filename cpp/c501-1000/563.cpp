

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int postOrder(TreeNode* node, int& totalTilt){
            if (node == nullptr) return 0;
    
            int leftSum = postOrder(node->left, totalTilt);
            int rightSum = postOrder(node->right, totalTilt);
    
            int tilt = abs(leftSum - rightSum);
            totalTilt += tilt;
    
            return leftSum + rightSum + node->val;
        }
        int findTilt(TreeNode* root) {
            int totalTilt = 0;
            postOrder(root, totalTilt);
            return totalTilt;
        }
    };