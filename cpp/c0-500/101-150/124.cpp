#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // Initialize the global maximum to a very small value
        dfs(root, maxSum);
        return maxSum;
    }

private:
    // Helper function to perform DFS and calculate max path sum
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;  // If node is null, return 0 (no contribution to the path sum)

        // Recursively calculate the maximum path sum for the left and right children
        int leftMax = max(dfs(node->left, maxSum), 0);  // Only take positive contributions
        int rightMax = max(dfs(node->right, maxSum), 0);  // Only take positive contributions

        // The maximum path sum for the current node includes:
        // 1. The node itself
        // 2. The best possible path through the left child (if positive)
        // 3. The best possible path through the right child (if positive)
        int currentMaxPath = node->val + leftMax + rightMax;

        // Update the global maximum sum if we find a higher sum
        maxSum = max(maxSum, currentMaxPath);

        // Return the maximum path sum that extends from the current node to its parent
        return node->val + max(leftMax, rightMax);
    }
};

int main() {
    Solution sol;

    // Example 1:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << "Maximum path sum for root1: " << sol.maxPathSum(root1) << endl;  // Output: 6

    // Example 2:
    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    cout << "Maximum path sum for root2: " << sol.maxPathSum(root2) << endl;  // Output: 42

    return 0;
}
