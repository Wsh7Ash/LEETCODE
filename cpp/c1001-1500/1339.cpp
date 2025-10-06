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
        long long totalSum = 0;
        long long maxP = 0;
        const int MOD = 1e9 + 7;
    
    public:
        int maxProduct(TreeNode* root) {
            totalSum = calculateSum(root);
            calculateMaxProduct(root);
    
            return maxP % MOD;
        }
    
    private:
        // long long totalSum = 0;
        // long long maxProduct = 0;
        // long long MOD = 1e9 + 7;
    
        long long calculateSum(TreeNode* node){
            if(!node) return 0;
            return node->val + calculateSum(node->left) + calculateSum(node->right);
        }
    
        long long calculateMaxProduct(TreeNode* node){
            if(!node) return 0;
    
            long long subtreeSum = node->val + calculateMaxProduct(node->left) + calculateMaxProduct(node->right);
    
            
            long long product = subtreeSum * (totalSum - subtreeSum);
            maxP = max(maxP, product);
            
    
            return subtreeSum;
        }
    };