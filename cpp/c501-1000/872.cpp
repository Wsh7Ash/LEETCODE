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
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> l1;
            vector<int> l2;
            collectLeaves(root1, l1);
            collectLeaves(root2, l2);
            return l1 == l2;
        }
        void collectLeaves(TreeNode* node, vector<int>& l){
            if(node == nullptr) return;
            if(node->left == nullptr && node->right == nullptr) l.push_back(node->val);
            collectLeaves(node->left, l);
            collectLeaves(node->right, l);
        }
    };