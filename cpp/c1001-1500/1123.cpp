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
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfs(root).second;
        }
    private:
        pair<int, TreeNode*> dfs(TreeNode* node){
            if(!node) return {0, nullptr};
            auto left = dfs(node->left);
            auto right = dfs(node->right);
            int left_depth = left.first;
            int right_depth = right.first;
            if(left_depth > right_depth) return {left_depth + 1, left.second};
            if(left_depth < right_depth) return {right_depth + 1, right.second};
            else{
                return{left_depth + 1, node};
            }
        }
    };