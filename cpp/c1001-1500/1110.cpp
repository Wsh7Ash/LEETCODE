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
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            unordered_set<int> tds(to_delete.begin(), to_delete.end());
            vector<TreeNode*> forest;
            if(root == nullptr) return forest;
            if(tds.find(root->val) == tds.end()) forest.push_back(root);
            dfs(root, tds, forest);
            return forest;
        }
    private:
        TreeNode* dfs(TreeNode* node, unordered_set<int>& tds, vector<TreeNode*>& forest){
            if(node == nullptr) return nullptr;
            node->left = dfs(node->left, tds, forest);
            node->right = dfs(node->right, tds, forest);
            if(tds.find(node->val) != tds.end()){
                if(node->left != nullptr){    
                    forest.push_back(node->left);
                }if(node->right != nullptr){
                    forest.push_back(node->right);
                }
                return nullptr;
            }
            return node;
        }
    };