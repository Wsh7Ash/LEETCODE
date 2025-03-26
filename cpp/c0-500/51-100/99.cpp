class Solution {
    public:
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
    
        void inorder(TreeNode* root) {
            if (!root) return;
            
            inorder(root->left); // Traverse left subtree
            
            // Check for violation in the BST property
            if (prev && prev->val > root->val) {
                if (!first) {
                    first = prev;  // The first node to be swapped
                }
                second = root;  // The second node to be swapped
            }
            
            prev = root; // Update the previous node
            
            inorder(root->right); // Traverse right subtree
        }
    
        void recoverTree(TreeNode* root) {
            inorder(root); // Perform in-order traversal to find the swapped nodes
            swap(first->val, second->val); // Swap the values of the two nodes
        }
    };
    