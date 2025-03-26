#include <iostream>
#include <vector>
#include <queue>
#include <deque>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result; // Return empty if tree is empty

        queue<TreeNode*> q; // Queue for BFS traversal
        q.push(root);
        bool leftToRight = true; // Flag to track zigzag direction

        while (!q.empty()) {
            int size = q.size();
            deque<int> level; // Deque to store nodes in zigzag order

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Insert nodes based on zigzag order
                if (leftToRight)
                    level.push_back(node->val);
                else
                    level.push_front(node->val);

                // Enqueue left and right children
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(vector<int>(level.begin(), level.end())); // Convert deque to vector
            leftToRight = !leftToRight; // Toggle direction for next level
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print the zigzag level order traversal result
    printResult(result);

    return 0;
}
