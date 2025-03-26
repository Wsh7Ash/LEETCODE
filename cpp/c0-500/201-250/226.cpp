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
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            // Base case: if null, return null
            if (!root) {
                return nullptr;
            }
            
            // Swap left and right children
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            
            // Recursively invert left and right subtrees
            invertTree(root->left);
            invertTree(root->right);
            
            return root;
        }
    };
    // Let's break down how this solution works:
    
    // Approach:
    // Use recursion to traverse the tree
    // For each node, swap its left and right children
    // Recursively process each subtree
    // Key Steps:
    // Check for null node (base case)
    // Swap left and right pointers using a temporary variable
    // Recursively invert both subtrees
    // Return the modified root
    // Time and Space Complexity:
    // Time Complexity: O(n) where n is the number of nodes
    // Space Complexity: O(h) where h is the height of the tree (due to recursion stack)
    // Worst case: O(n) for skewed tree
    // Average case: O(log n) for balanced tree
    // Example 1 Walkthrough:
    // text
    // Wrap
    // Copy
    // Input:     4
    //          /   \
    //         2     7
    //        / \   / \
    //       1   3 6   9
    
    // Process:
    // - At 4: swap 2 and 7
    // - At 7: swap 6 and 9
    // - At 2: swap 1 and 3
    
    // Output:    4
    //          /   \
    //         7     2
    //        / \   / \
    //       9   6 3   1
    // Correctness:
    // Handles empty tree (Example 3)
    // Works for single node trees
    // Correctly inverts all levels of larger trees
    // The solution handles all test cases:
    
    // Example 1: [4,2,7,1,3,6,9] → [4,7,2,9,6,3,1]
    // Example 2: [2,1,3] → [2,3,1]
    // Example 3: [] → []
    // Key Features:
    
    // Simple and elegant recursive solution
    // Meets all constraints (0-100 nodes, -100 to 100 values)
    // Modifies tree in-place
    // Returns the root as required
    // Alternative Iterative Approach:
    // We could also solve this using a queue or stack for level-order or depth-first traversal, but the recursive solution is more concise and equally efficient for this problem since we need to visit every node regardless of the approach.
    
    // This implementation provides a clean, efficient way to invert a binary tree while maintaining the problem's requirements and constraints.