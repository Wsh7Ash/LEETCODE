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
        bool isUnivalTree(TreeNode* root) {
            if(root == nullptr) return true;
            int v = root->val;
            return helper(root, v);
        }
    private:
        bool helper(TreeNode* node, int v){
            if(node == nullptr) return true;
            if(node->val != v) return false;
            return helper(node->left, v) && helper(node->right, v);
        }
    };