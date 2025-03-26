// To find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST), we can leverage the properties of a BST:

// Left Subtree: All nodes in the left subtree of a node have values less than the node's value.

// Right Subtree: All nodes in the right subtree of a node have values greater than the node's value.

// Using these properties, we can efficiently find the LCA without traversing the entire tree.

// Approach:
// Start at the Root:

// Begin traversing the BST from the root node.

// Compare Values:

// If both p and q are greater than the current node's value, move to the right subtree.

// If both p and q are less than the current node's value, move to the left subtree.

// If one node is greater and the other is less than the current node's value, the current node is the LCA.

// Return the LCA:

// Once the above condition is met, return the current node as the LCA.

// Solution Code:
// cpp
// Copy
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                // Both p and q are in the right subtree
                root = root->right;
            } else if (p->val < root->val && q->val < root->val) {
                // Both p and q are in the left subtree
                root = root->left;
            } else {
                // Current node is the LCA
                return root;
            }
        }
        return nullptr; // This will never be reached as per constraints
    }
};
// Explanation:
// Traversal:

// We start at the root and compare the values of p and q with the current node's value.

// If both p and q are greater than the current node's value, we move to the right subtree.

// If both p and q are less than the current node's value, we move to the left subtree.

// LCA Condition:

// If one node is greater and the other is less than the current node's value, the current node is the LCA because p and q are in different subtrees.

// Efficiency:

// The time complexity is 
// O
// (
// h
// )
// O(h), where 
// h
// h is the height of the BST. In the worst case, 
// h
// =
// n
// h=n (for a skewed tree), but for a balanced BST, 
// h
// =
// log
// ⁡
// n
// h=logn.

// The space complexity is 
// O
// (
// 1
// )
// O(1) since we are using iterative traversal.

// Example Walkthrough:
// Example 1:
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8

// Output: 6

// Execution:
// Start at root (6).

// Compare 2 and 8 with 6:

// 2 < 6 and 8 > 6, so 6 is the LCA.

// Example 2:
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4

// Output: 2

// Execution:
// Start at root (6).

// Compare 2 and 4 with 6:

// Both 2 and 4 are less than 6, so move to the left subtree (2).

// Compare 2 and 4 with 2:

// 2 == 2 and 4 > 2, so 2 is the LCA.

// Example 3:
// Input: root = [2,1], p = 2, q = 1

// Output: 2

// Execution:
// Start at root (2).

// Compare 2 and 1 with 2:

// 2 == 2 and 1 < 2, so 2 is the LCA.

// Key Points:
// The solution leverages the properties of a BST to efficiently find the LCA.

// The time complexity is 
// O
// (
// h
// )
// O(h), where 
// h
// h is the height of the BST.

// The space complexity is 
// O
// (
// 1
// )
// O(1) for iterative traversal.