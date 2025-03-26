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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int& postorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
        if (inorderStart > inorderEnd) return nullptr; // Base case: empty subtree

        // Get the root value from postorder (last element in postorder subarray)
        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root index in inorder
        int rootIndexInInorder = inorderMap[rootVal];

        // Recursively build the right and left subtrees (note the reversed order for right subtree first)
        root->right = buildTree(inorder, postorder, postorderIndex, rootIndexInInorder + 1, inorderEnd, inorderMap);
        root->left = buildTree(inorder, postorder, postorderIndex, inorderStart, rootIndexInInorder - 1, inorderMap);

        return root;
    }

    TreeNode* constructBinaryTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i; // Store the index of each element in inorder
        }

        int postorderIndex = postorder.size() - 1; // Start from the last element of postorder
        return buildTree(inorder, postorder, postorderIndex, 0, inorder.size() - 1, inorderMap);
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
    // Constructing the binary tree from inorder and postorder traversals
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.constructBinaryTree(inorder, postorder);

    // Printing the constructed binary tree (level order)
    printTree(root); // Expected Output: 3 9 20 null null 15 7

    return 0;
}
