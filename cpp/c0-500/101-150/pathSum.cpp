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
    vector<vector<int>> result; // Stores all valid paths

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return; // Base case: If root is null, return

        // Add current node to the path
        path.push_back(root->val);

        // Check if it's a leaf node and the sum is correct
        if (!root->left && !root->right && targetSum == root->val) {
            result.push_back(path); // Store the valid path
        } else {
            // Recursively explore left and right subtrees
            dfs(root->left, targetSum - root->val, path);
            dfs(root->right, targetSum - root->val, path);
        }

        // Backtrack: Remove the last element before returning
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};

// Helper function to create the sample tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    return root;
}

// Function to print the result
void printResult(const vector<vector<int>>& paths) {
    cout << "[";
    for (const auto& path : paths) {
        cout << "[";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createTree();
    cout << "Paths with sum 22: ";
    printResult(sol.pathSum(root1, 22));

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << "Paths with sum 5: ";
    printResult(sol.pathSum(root2, 5));

    TreeNode* root3 = nullptr;
    cout << "Paths with sum 0: ";
    printResult(sol.pathSum(root3, 0));

    return 0;
}
