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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> avgs;
            if(root == nullptr) return avgs;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                long sum = 0;
                int count = q.size();
                int levelSize = count;
                for(int i = 0; i < levelSize; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    sum += node->val;
    
                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                avgs.push_back(double(sum) / levelSize);
            }
            return avgs;
    
        }
    };