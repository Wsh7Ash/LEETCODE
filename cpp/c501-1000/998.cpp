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
        TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
           vector<int> nums;
           inorder(root, nums);
           nums.push_back(val);
           return construct(nums, 0, nums.size() - 1); 
        }
    private:
        void inorder(TreeNode* node, vector<int>& nums){
            if(!node)return;
            inorder(node->left, nums);
            nums.push_back(node->val);
            inorder(node->right, nums);
        }
    
        TreeNode* construct(vector<int>& nums, int start, int end){
            if(start > end) return nullptr;
            int maxIndex = start;
            for(int i = start + 1; i <= end; i++){
                if(nums[i] > nums[maxIndex]){
                    maxIndex = i;
                }
            }
    
            TreeNode* root = new TreeNode(nums[maxIndex]);
            root->left = construct(nums, start, maxIndex - 1);
            root->right = construct(nums, maxIndex + 1, end);
            return root;
        }
    };