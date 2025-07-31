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
        bool isCousins(TreeNode* root, int x, int y) {
            if(root == nullptr) return false;
    
            queue<pair<TreeNode*, TreeNode*>> q;
            q.push({root, nullptr});
    
            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;
            int xDepth = -1, yDepth = -1;
            int depth = 0;
    
            while(!q.empty()){
                int levelSize = q.size();
                for(int i = 0; i < levelSize; i++){
                    auto current = q.front();
                    q.pop();
                    TreeNode* node = current.first;
                    TreeNode* parent = current.second;
    
                    if(node->val == x){
                        xParent = parent;
                        xDepth = depth;
                    }
                    if(node->val == y){
                        yParent = parent;
                        yDepth = depth;
                    }
    
                    if(node->left) q.push({node->left, node});
                    if(node->right) q.push({node->right, node});
                }
                depth++;
    
                if(xParent != nullptr && yParent != nullptr) break;
            }
            return (xDepth == yDepth) && (xParent != yParent);
        }
    };