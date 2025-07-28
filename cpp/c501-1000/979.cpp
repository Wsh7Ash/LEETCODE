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
        int distributeCoins(TreeNode* root) {
            int m = 0;
            postOrder(root, m);
            return m;
        }
    private:
        int postOrder(TreeNode* node, int& m){
            if(node == nullptr) return 0;
            int l = postOrder(node->left, m);
            int r = postOrder(node->right, m);
            m += abs(l) + abs(r);
            return node->val + l + r - 1;
        }
    };