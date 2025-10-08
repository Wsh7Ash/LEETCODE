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
        int longestZigZag(TreeNode* root) {
            int maxLen = 0;
            dfs(root, maxLen);
            return maxLen;
        }
    private:
        pair<int, int> dfs(TreeNode* node, int& maxLen){
            if(!node) return {-1, -1};
    
            auto leftRes = dfs(node->left, maxLen);
            auto rightRes = dfs(node->right, maxLen);
    
            int goLeft = 1 + leftRes.second;
            int goRight = 1 + rightRes.first;
            maxLen = max(maxLen, max(goLeft, goRight));
    
            return {goLeft, goRight};
        }
    };