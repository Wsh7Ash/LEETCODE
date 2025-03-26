#include <iostream>
#include <vector>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        // Base case: if left > right, return null (empty subtree)
        if (left > right) return nullptr;

        // Find the middle element of the current subarray
        int mid = left + (right - left) / 2;

        // Create the current root node
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = buildTree(nums, left, mid - 1);  // Left subtree
        root->right = buildTree(nums, mid + 1, right); // Right subtree

        return root;
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
    // Input sorted array
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    // Printing the BST in level order
    printTree(root);  // Expected Output: [0, -3, 9, -10, null, 5]

    return 0;
}
