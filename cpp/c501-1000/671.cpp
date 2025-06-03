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
        void helper(TreeNode* node, int minVal, long& secMin){
            if(!node) return;
            if(node->val > minVal && node->val < secMin){
                secMin = node->val;
            }
            helper(node->left, minVal, secMin);
            helper(node->right, minVal, secMin);
        }
        int findSecondMinimumValue(TreeNode* root) {
            if(!root) return -1;
            int minVal = root->val;
            long secMin = LONG_MAX;
            helper(root, minVal, secMin);
            return secMin == LONG_MAX ? -1 : secMin;
        }
    };