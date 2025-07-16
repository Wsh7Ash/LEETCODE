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
class CBTInserter {
    public:
        TreeNode* root;
        queue<TreeNode*> candidateParents;
        CBTInserter(TreeNode* root) {
            this->root = root;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(node->left == nullptr || node->right == nullptr){
                    candidateParents.push(node);
                }
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }
        
        int insert(int val) {
            TreeNode* parent = candidateParents.front();
            TreeNode* newNode = new TreeNode(val);
            if(parent->left == nullptr){
                parent->left = newNode;
            }else{
                parent->right = newNode;
                candidateParents.pop();
            }
            candidateParents.push(newNode);
            return parent->val;
        }
    
        
        TreeNode* get_root() {
            return root;    
        }
    };
    
    /**
     * Your CBTInserter object will be instantiated and called as such:
     * CBTInserter* obj = new CBTInserter(root);
     * int param_1 = obj->insert(val);
     * TreeNode* param_2 = obj->get_root();
     */