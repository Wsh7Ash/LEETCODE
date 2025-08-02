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
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int index = 0;
            return helper(preorder, index, numeric_limits<int>::max());
        }
    
    private:
        TreeNode* helper(vector<int>& preorder, int& index, int upper_bound){
            if(index >= preorder.size() || preorder[index] > upper_bound) return nullptr;
            int val = preorder[index++];
            TreeNode* root = new TreeNode(val);
            root->left = helper(preorder, index, val);
            root->right = helper(preorder, index, upper_bound);
            return root;
        }
    };