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
        int ls, rs;
        
        int countNodes(TreeNode* root){
            if(root == nullptr) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    
        TreeNode* findNode(TreeNode* root, int x){
            if(root == nullptr) return nullptr;
            if(root->val == x) return root;
            TreeNode* left = findNode(root->left, x);
            if(left) return left;
            return findNode(root->right, x);
        }
    
        bool btreeGameWinningMove(TreeNode* root, int n, int x) {
            TreeNode* nodex = findNode(root, x);
            ls = countNodes(nodex->left);
            rs = countNodes(nodex->right);
            int ps =  n - (ls + rs + 1);
    
            int maxPart = max({ls, rs, ps});
            return maxPart > (n - maxPart);
        }
    };