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
        vector<vector<string>> printTree(TreeNode* root) {
            int height = getHeight(root);
            int m = height + 1;
            int n = (1 << (height + 1)) - 1;
            vector<vector<string>> res(m, vector<string>(n, ""));
            fillMatrix(root, res, 0, 0, n-1);
            return res;
        }
        int getHeight(TreeNode* node){
            if(!node) return  -1;
            return 1+max(getHeight(node->left), getHeight(node->right));
        }
        void fillMatrix(TreeNode* node, vector<vector<string>>& res, int row, int left, int right){
            if(!node) return;
            int mid = left + (right - left) /2;
            res[row][mid] = to_string(node->val);
            fillMatrix(node->left, res, row+1, left, mid-1);
            fillMatrix(node->right, res, row+1, mid+1, right);
        }
    };