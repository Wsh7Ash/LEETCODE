class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // If both trees are empty, they are the same
            if (!p && !q) return true;
            
            // If one tree is empty and the other is not, they are not the same
            if (!p || !q) return false;
            
            // If the values of the nodes are different, the trees are not the same
            if (p->val != q->val) return false;
            
            // Recursively check the left and right subtrees
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };
    