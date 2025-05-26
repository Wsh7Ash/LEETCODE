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
        int widthOfBinaryTree(TreeNode* root) {
            if(!root) return 0;
            queue<pair<TreeNode*, unsigned long long>> q;
            q.push({root, 0});
            unsigned long long max_width = 0;
            while(!q.empty()){
                unsigned long long level_size = q.size();
                unsigned long long left_index = q.front().second;
                unsigned long long right_index = left_index;
    
                for(unsigned long long i = 0; i < level_size; i++){
                    auto cur = q.front();
                    q.pop();
                    right_index = cur.second;
    
                    if(cur.first->left){
                        q.push({cur.first->left, 2*right_index});
                    }
                    if(cur.first->right){
                        q.push({cur.first->right, 2*right_index + 1});
                    }
                }
                unsigned long long cur_width = right_index - left_index + 1;
                if(cur_width > max_width){
                    max_width = cur_width;
                }
            }
            return max_width;
        }
    };