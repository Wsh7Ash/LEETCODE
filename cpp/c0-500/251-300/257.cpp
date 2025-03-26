/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;
        if (root) {
            dfs(root, std::to_string(root->val), paths);
        }
        return paths;
    }
    
private:
    void dfs(TreeNode* node, std::string currentPath, std::vector<std::string>& paths) {
        // If it's a leaf node, add the path to results
        if (!node->left && !node->right) {
            paths.push_back(currentPath);
            return;
        }
        
        // Recurse on left child if it exists
        if (node->left) {
            dfs(node->left, currentPath + "->" + std::to_string(node->left->val), paths);
        }
        
        // Recurse on right child if it exists
        if (node->right) {
            dfs(node->right, currentPath + "->" + std::to_string(node->right->val), paths);
        }
    }
};
// Let's break down how this solution works:

// Main Function (binaryTreePaths):
// Initializes an empty vector to store all paths
// Checks if root exists, then starts DFS with initial path as root's value
// Returns the complete list of paths
// Helper DFS Function:
// Takes current node, current path string, and reference to paths vector
// Base case: if node is a leaf (no children), add current path to results
// Recursive case:
// If left child exists, recurse with path extended by "->" and left child's value
// If right child exists, recurse with path extended by "->" and right child's value
// Key Features:
// Uses string concatenation to build paths
// Handles the arrow notation "->" as required
// Processes nodes depth-first from root to leaves
// Time and Space Complexity:
// Time Complexity: O(n), where n is number of nodes (visits each node once)
// Space Complexity: O(h) for recursion stack, where h is height of tree
// In worst case (skewed tree), could be O(n)
// Additional space for storing paths: O(n * h) for all path strings
// Example walkthrough for [1,2,3,null,5]:

// Start at 1: path = "1"
// Go left to 2: path = "1->2"
// Go left to 5: path = "1->2->5" (leaf, add to results)
// Back to 1, go right to 3: path = "1->3" (leaf, add to results)
// Result: ["1->2->5", "1->3"]
// The solution handles all constraints:

// Works for 1 to 100 nodes
// Handles node values from -100 to 100
// Returns paths in any order as allowed
// Correctly identifies leaf nodes (no children)
// Produces properly formatted strings with "->" separators