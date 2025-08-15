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
        TreeNode* sufficientSubset(TreeNode* root, int limit) {
            return helper(root, 0, limit);
        }
    
        TreeNode* helper(TreeNode* node, int curSum, int limit){
            if(!node) return nullptr;
    
            curSum += node->val;
    
            if(!node->left && !node->right){
                if(curSum < limit){
                    return nullptr;
                }
                else{
                    return node;
                }
            }
    
            node->left = helper(node->left, curSum, limit);
            node->right = helper(node->right, curSum, limit);
    
            if(!node->left && !node->right){
                return nullptr;
    
            }
            else{
                return node;
            }
        }
    };