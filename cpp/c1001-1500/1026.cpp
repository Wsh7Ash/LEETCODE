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
        int maxAncestorDiff(TreeNode* root) {
            if(!root) return 0;
            int maxDiff = 0;
            dfs(root, root->val, root->val, maxDiff);
            return maxDiff;
        }
    
    private:
        void dfs(TreeNode* node, int cmin, int cmax, int& maxDiff){
            if(!node) return;
    
            int diff = max(abs(node->val - cmin), abs(node->val - cmax));
            maxDiff = max(maxDiff, diff);
    
            cmin = min(cmin, node->val);
            cmax = max(cmax, node->val);
        
            dfs(node->left, cmin, cmax, maxDiff);
            dfs(node->right, cmin, cmax, maxDiff);
        }
    };