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
        string smallestFromLeaf(TreeNode* root) {
            string smallest;
            string current;
            dfs(root, current, smallest);
            return smallest;
        }
    private:
        void dfs(TreeNode* node, string& current, string& smallest){
            if(!node) return;
            current.push_back('a' + node->val);
            if(!node->left && !node->right){
                string path = current;
                reverse(path.begin(), path.end());
                if(smallest.empty() || path < smallest){
                    smallest = path;
                }
            }
            dfs(node->left, current, smallest);
            dfs(node->right, current, smallest);
    
            current.pop_back();
        }
    };