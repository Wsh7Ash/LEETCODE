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
        int longestUnivaluePath(TreeNode* root) {
            int mlen = 0;
            dfs(root, mlen);
            return mlen;
        }
        int dfs(TreeNode* node, int& mlen){
            if(!node) return 0;
            int l = dfs(node->left, mlen);
            int r = dfs(node->right, mlen);
            int lp = 0, rp = 0;
            if(node->left && node->left->val == node->val){
                lp = l + 1;
            }
            if(node->right && node->right->val == node->val){
                rp = r + 1;
            }
            mlen = max(mlen, lp + rp);
            return max(lp, rp);
        }
    };