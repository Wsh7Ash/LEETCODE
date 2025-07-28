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
        vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
            vector<int> flips;
            int index = 0;
            bool possible = dfs(root, voyage, index,  flips);
            if(!possible) return {-1};
            return flips;
        }
    private:
        bool dfs(TreeNode* node, vector<int>& voyage, int& index, vector<int>& flips){
            if(!node) return true;
            if(node->val != voyage[index++]) return false;
            if(node->left && node->left->val != voyage[index]){
                flips.push_back(node->val);
                return dfs(node->right, voyage, index, flips) && dfs(node->left, voyage, index, flips);
            }else{
                return dfs(node->left, voyage, index, flips) && dfs(node->right, voyage, index, flips);
            }
        }
    };