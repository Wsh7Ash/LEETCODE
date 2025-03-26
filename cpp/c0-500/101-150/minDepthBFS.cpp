#include <iostream>
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
    // Recursive Approach (DFS)
    int minDepth(TreeNode* root) {
        if (!root) return 0; // Base case: empty tree
        
        // If left subtree is NULL, return depth of right subtree + 1
        if (!root->left) return 1 + minDepth(root->right);
        // If right subtree is NULL, return depth of left subtree + 1
        if (!root->right) return 1 + minDepth(root->left);
        
        // Both children exist, take the minimum depth of both
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    // Iterative Approach (BFS)
    int minDepthBFS(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            // If it's a leaf node, return its depth
            if (!node->left && !node->right) return depth;

            // Push children into the queue with incremented depth
            if (node->left) q.push({node->left, depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }
        return 0;
    }
};

// Helper function to create a sample tree for testing
TreeNode* createTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    
    // Test case: Balanced tree
    TreeNode* root1 = createTree();
    cout << "Minimum depth (DFS): " << sol.minDepth(root1) << endl;
    cout << "Minimum depth (BFS): " << sol.minDepthBFS(root1) << endl;

    // Test case: Skewed tree [2, null, 3, null, 4, null, 5, null, 6]
    TreeNode* root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->right->right = new TreeNode(5);
    root2->right->right->right->right = new TreeNode(6);

    cout << "Minimum depth (DFS): " << sol.minDepth(root2) << endl;
    cout << "Minimum depth (BFS): " << sol.minDepthBFS(root2) << endl;

    return 0;
}
