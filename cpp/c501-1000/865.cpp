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
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            return helper(root).first;
        }
        pair<TreeNode*, int> helper(TreeNode* node){
            if(!node) return {nullptr, 0};
            auto l = helper(node->left);
            auto r = helper(node->right);
            if(l.second>r.second) return {l.first, l.second + 1};
            if(l.second<r.second) return {r.first, r.second + 1};
            return {node, l.second + 1};
        }
    };