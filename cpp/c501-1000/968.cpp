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
        int c = 0;
        int minCameraCover(TreeNode* root) {
            int rootState = dfs(root);
            if(rootState == 0) c++;
            return c;
        }
    
        int dfs(TreeNode* node){
            if(node == nullptr) return 1;
            int l = dfs(node->left);
            int r = dfs(node->right);
    
            if(l == 0 || r == 0) {
                c++;
                return 2;
            }else if(l == 2 || r == 2) return 1;
            else{
                return 0;
            }
        }
    };