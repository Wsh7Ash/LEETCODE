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
class FindElements {
    public:
        FindElements(TreeNode* root) {
            this->root = root;
            recoverTree(root, 0);
        }
        
        bool find(int target) {
            return validValues.count(target) > 0;
        }
    private:
        TreeNode* root;
        unordered_set<int> validValues;
    
        void recoverTree(TreeNode* node, int value){
            if(!node) return;
    
            node->val = value;
            validValues.insert(value);
    
            if(node->left)recoverTree(node->left, 2 * value + 1);
            if(node->right)recoverTree(node->right, 2 * value + 2);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */