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
        vector<TreeNode*> allPossibleFBT(int n) {
            if(n % 2 == 0) return {};
            if(n == 1) return {new TreeNode(0)};
    
            vector<TreeNode*> res;
            for(int lN = 1; lN < n; lN++){
                int rN = n - 1 - lN;
                vector<TreeNode*> lSt = allPossibleFBT(lN);
                vector<TreeNode*> rSt = allPossibleFBT(rN);
                for(TreeNode* l : lSt){
                    for(TreeNode* r : rSt){
                        TreeNode* root = new TreeNode(0);
                        root->left = l; 
                        root->right = r;
                        res.push_back(root); 
                    }
                }
            }
            return res;
        }
    };