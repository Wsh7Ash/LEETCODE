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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;  // To store the final bottom-up level order traversal
        if (!root) return result;  // If tree is empty, return an empty result

        queue<TreeNode*> q;  // Queue for BFS
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            vector<int> levelValues;   // To store values at the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);  // Add node value to current level list

                // Add children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(levelValues);  // Add current level to result
        }

        // Reverse the result to get bottom-up level order
        reverse(result.begin(), result.end());

        return result;
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
    // Constructing the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrderBottom(root);

    // Printing the bottom-up level order traversal
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
