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
        TreeNode* increasingBST(TreeNode* root) {
            vector<TreeNode*> nodes;
            inOrder(root, nodes);
            for(int i = 0; i <  nodes.size() - 1; i++){
                nodes[i]->left = nullptr;
                nodes[i]->right = nodes[i+1]; 
            }
            nodes.back()->left = nullptr;
            nodes.back()->right = nullptr;
            return nodes[0];
        }
        void inOrder(TreeNode* node, vector<TreeNode*>& nodes){
            if(node == nullptr) return;
            inOrder(node->left, nodes);
            nodes.push_back(node);
            inOrder(node->right, nodes);
        }
    };