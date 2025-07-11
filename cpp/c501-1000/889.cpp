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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            unordered_map<int, int> postMap;
            for(int i = 0; i < postorder.size(); i++){
                postMap[postorder[i]] = i;
            }
            return buildTree(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postMap);
        }
    
        TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& postMap){
            if(preStart > preEnd) return nullptr;
            TreeNode* root = new TreeNode(preorder[preStart]);
            if(preStart == preEnd) return root;
    
            int lRV = preorder[preStart + 1];
            int lRPI = postMap[lRV];
            int lSS = lRPI - postStart + 1;
    
            root->left = buildTree(preorder, preStart + 1, preStart + lSS, postorder, postStart, lRPI, postMap);
            root->right = buildTree(preorder, preStart + lSS + 1, preEnd, postorder, lRPI + 1, postEnd - 1, postMap);
            return root;
        }
    };