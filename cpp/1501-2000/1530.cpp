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
        int countPairs(TreeNode* root, int distance) {
            int res =0;
            dfs(root, distance, res);
            return res;
        }
    
    private:
    
        vector<int> dfs(TreeNode* node, int distance, int& res){
            if(!node) return {};
            if(!node->left && !node->right) return {1};
            vector<int> left = dfs(node->left, distance, res);
            vector<int> right = dfs(node->right, distance, res);
    
            for(int i = 0; i < left.size(); i++){
                for(int j = 0; j < right.size(); j++){
                    if(i + j + 2 <= distance){
                        res += (left[i] * right[j]);
                    }
                }
            }
    
            vector<int> distCount(max(left.size(), right.size()) + 1, 0);
            for(int i = 0; i <left.size(); i++){
                distCount[i+1] += left[i];
            }
            for(int i = 0; i <right.size(); i++){
                distCount[i+1] += right[i];
            }
            return distCount;
        } 
    };