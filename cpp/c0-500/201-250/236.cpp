Here's a C++ solution using recursion to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree:

Lowest Common Ancestor
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
#include <iostream>

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
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root; // If p and q are found in different subtrees
        
        return left ? left : right; // Return non-null subtree (either left or right)
    }
};


Answer in chat instead
Explanation:
Base Case: If the root is nullptr, or if root matches either p or q, return root.
Recursive Calls: Recursively search for p and q in the left and right subtrees.
Check Subtree Results:
If both left and right are non-null, root is the LCA.
Otherwise, return the non-null node (either left or right), which means both p and q are in that subtree.
This approach runs in O(n) time complexity, where n is the number of nodes, as it traverses the tree once.