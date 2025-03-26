#include <iostream>
#include <vector>
#include <unordered_map>

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
    // Helper function to construct the binary tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
        if (inorderStart > inorderEnd) return nullptr; // Base case: empty subtree

        // Get the root value from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root index in inorder
        int rootIndexInInorder = inorderMap[rootVal];

        // Recursively build the left and right subtrees
        root->left = buildTree(preorder, inorder, preorderIndex, inorderStart, rootIndexInInorder - 1, inorderMap);
        root->right = buildTree(preorder, inorder, preorderIndex, rootIndexInInorder + 1, inorderEnd, inorderMap);

        return root;
    }

    TreeNode* constructBinaryTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i; // Store the index of each element in inorder
        }

        int preorderIndex = 0;
        return buildTree(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
    }
};

// Helper function to print the tree in level order (for testing purposes)
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Test case
int main() {
    // Constructing the binary tree from preorder and inorder traversals
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.constructBinaryTree(preorder, inorder);

    // Printing the constructed binary tree (level order)
    printTree(root); // Expected Output: 3 9 20 null null 15 7

    return 0;
}
