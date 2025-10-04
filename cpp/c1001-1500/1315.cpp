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
        int sumEvenGrandparent(TreeNode* root) {
            return dfs(root, nullptr, nullptr);
        }
    
    private:
        int dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent){
            if(node == nullptr) return 0;
            int sum = 0;
            if(grandparent != nullptr && grandparent->val % 2 == 0) sum += node->val;
    
            sum += dfs(node->left, node, parent);
            sum += dfs(node->right, node, parent);
    
            return sum;
        }
    };