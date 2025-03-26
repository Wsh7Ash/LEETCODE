#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // If left subtree exists
        if (root->left) {
            TreeNode* rightMost = root->left;
            
            // Find the rightmost node of the left subtree
            while (rightMost->right) {
                rightMost = rightMost->right;
            }
            
            // Connect rightmost node to the original right subtree
            rightMost->right = root->right;

            // Move left subtree to right and set left to null
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

// Helper function to print flattened tree
void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

// Function to create a sample tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;

    TreeNode* root1 = createTree();
    sol.flatten(root1);
    cout << "Flattened Tree: ";
    printFlattened(root1);

    TreeNode* root2 = nullptr;
    sol.flatten(root2);
    cout << "Flattened Tree (empty): ";
    printFlattened(root2);

    TreeNode* root3 = new TreeNode(0);
    sol.flatten(root3);
    cout << "Flattened Tree: ";
    printFlattened(root3);

    return 0;
}
