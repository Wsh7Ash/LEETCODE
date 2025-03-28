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
        unordered_map<int, int> sumFrequency;
        int maxFrequency = 0;
        
        int computeSubtreeSum(TreeNode* node){
            if(node == nullptr){
                return 0;
            }
            int leftSum = computeSubtreeSum(node->left);
            int rightSum = computeSubtreeSum(node->right);
            int curSum = node->val + leftSum + rightSum;
    
            sumFrequency[curSum]++;
            if(sumFrequency[curSum] > maxFrequency){
                maxFrequency = sumFrequency[curSum];
            }
            return curSum;
        }
        vector<int> findFrequentTreeSum(TreeNode* root) {
            computeSubtreeSum(root);
            vector<int> res;
            for(const auto& pair : sumFrequency){
                if(pair.second == maxFrequency){
                    res.push_back(pair.first);
                }
            }
            return res;
        }
    };