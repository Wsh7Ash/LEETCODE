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
        int minDiffInBST(TreeNode* root) {
            vector<int> vs;
            inOrderTraversal(root, vs);
            int md = INT_MAX;
            for(int i = 1; i < vs.size(); i++){
                md = min(md, vs[i] - vs[i-1]);
            }
            return md;
        }
        void inOrderTraversal(TreeNode* node, vector<int>& vs){
            if(node == nullptr) return;
            inOrderTraversal(node->left, vs);
            vs.push_back(node->val);
            inOrderTraversal(node->right, vs);
        }
    };