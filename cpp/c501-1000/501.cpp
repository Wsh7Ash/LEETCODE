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
        vector<int> modes;
        int curVal = 0;
        int curCount = 0;
        int maxCount = 0;
    
        void inorder(TreeNode* root){
            if(root == nullptr)return;
            inorder(root->left);
            handleValue(root->val);
            inorder(root->right);
        }
        void handleValue(int val){
            if(val != curVal){
                curVal = val;
                curCount = 0;
            }
            curCount++;
            if(curCount > maxCount){
                maxCount = curCount;
                modes.clear();
                modes.push_back(val);
            }else if(curCount == maxCount){
                modes.push_back(val);
            }
        }
        vector<int> findMode(TreeNode* root) {
            inorder(root);
            return modes;
        }
    };