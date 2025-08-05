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
        TreeNode* recoverFromPreorder(string traversal) {
            stack<pair<TreeNode*, int>> stack;
            int index = 0;
            int n = traversal.size();
            TreeNode* root = nullptr;
    
            while(index < n){
                int depth = 0;
                while(index < n && traversal[index] == '-'){
                    depth++;
                    index++;
                }
    
                int value = 0;
                while(index < n && isdigit(traversal[index])){
                    value = value * 10 + (traversal[index] - '0');
                    index++;
                }
    
                TreeNode* node = new TreeNode(value);
                if(depth == 0){
                    root = node;
                    stack.push({node, depth});
                }else{
                    while(stack.top().second != depth - 1) stack.pop();
    
                    TreeNode* parent = stack.top().first;
                    if(parent->left == nullptr) parent->left = node;
                    else parent->right = node;
                    stack.push({node, depth});
                }
            }
            return root;
        }
    };