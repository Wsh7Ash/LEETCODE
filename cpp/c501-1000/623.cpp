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
        TreeNode* addOneRow(TreeNode* root, int val, int depth) {
            if(depth == 1){
                TreeNode* newRoot = new TreeNode(val);
                newRoot->left = root;
                return newRoot;
            }
            queue<TreeNode*> q;
            q.push(root);
            int curDepth = 1;
    
            while(!q.empty()){
                int levelSize = q.size();
                if(curDepth == depth - 1){
                    for(int i = 0; i < levelSize; i++){
                        TreeNode* node = q.front();
                        q.pop();
                        TreeNode* leftChild = node->left;
                        TreeNode* rightChild = node->right;
    
                        node->left = new TreeNode(val);
                        node->left->left = leftChild;
                        node->right = new TreeNode(val);
                        node->right->right = rightChild;
                    }
                    break;
                }else{
                    for(int i = 0; i < levelSize; i++){
                        TreeNode* node = q.front();
                        q.pop();
                        if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);
                    }
                    curDepth++;
                }
            }
            return root;
        }
    };