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
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
            vector<int> res;
    
            iT(root1, res);
            iT(root2, res);
            
            sort(res.begin(), res.end());
    
            return res;
        }
    
    private:
        void iT(TreeNode* root, vector<int>& res){
            if(!root) return;
    
            iT(root->left, res);
            res.push_back(root->val);
            iT(root->right, res);
        }
    };