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
    private:
        struct BSTInfo{
            bool isBST;
            int sum;
            int minVal;
            int maxVal;
    
            BSTInfo(bool isBST, int sum, int minVal, int maxVal) : 
                    isBST(isBST), sum(sum), minVal(minVal), maxVal(maxVal) {}
        };
    
        BSTInfo dfs(TreeNode* node, int& maxSum){
            if(!node){
                return BSTInfo(true, 0, INT_MAX, INT_MIN);
            }
    
            BSTInfo leftInfo = dfs(node->left, maxSum);
            BSTInfo rightInfo = dfs(node->right, maxSum);
    
            if(leftInfo.isBST && rightInfo.isBST && node->val > leftInfo.maxVal && node->val < rightInfo.minVal){
                int sum = node->val + leftInfo.sum + rightInfo.sum;
                maxSum = max(maxSum, sum);
    
                int minVal = min(node->val, leftInfo.minVal);
                int maxVal = max(node->val, rightInfo.maxVal);
    
                return BSTInfo(true, sum, minVal, maxVal);
            }else{
                return BSTInfo(false, 0, 0, 0);
            }
        }
    
    public:
        int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        dfs(root, maxSum);
        return maxSum;    
        }
    };