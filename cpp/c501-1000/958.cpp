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
        bool isCompleteTree(TreeNode* root) {
            if(!root) return true;
            queue<TreeNode*> q;
            q.push(root);
            bool seenNonFull = false;
    
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
    
                if(node->left){
                    if(seenNonFull) return false;
                    q.push(node->left);
                }else{
                    seenNonFull = true;
                }
    
                if(node->right){
                    if(seenNonFull)return false;
                    q.push(node->right);
                }else{
                    seenNonFull = true;
                }
            }
            return true;
        }
    };