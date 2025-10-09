/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
        TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
            return dfs(original, cloned, target);
        }
    
    private:
        TreeNode* dfs(TreeNode* orig, TreeNode* clone, TreeNode* target){
            if(orig == nullptr) return nullptr;
            if(orig == target) return clone;
    
            TreeNode* left = dfs(orig->left, clone->left, target);
            if(left != nullptr) return left;
    
            return dfs(orig->right, clone->right, target);
        }
    };