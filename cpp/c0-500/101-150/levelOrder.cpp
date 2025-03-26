#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // Stores the final level order traversal
        if (!root) return result; // If tree is empty, return empty result

        queue<TreeNode*> q; // Queue for BFS traversal
        q.push(root); // Start BFS with the root node

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> level; // Stores nodes at the current level

            // Process all nodes in the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop(); // Remove it from the queue
                level.push_back(node->val); // Add node's value to the current level

                // Enqueue left child if it exists
                if (node->left) q.push(node->left);

                // Enqueue right child if it exists
                if (node->right) q.push(node->right);
            }

            result.push_back(level); // Store the level's values in the final result
        }

        return result;
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

// Test case
int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the level order traversal result
    printResult(result);

    return 0;
}
