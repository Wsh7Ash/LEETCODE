// To solve the Kth Smallest Element in a BST problem, we can leverage the properties of a Binary Search Tree (BST). In a BST, an in-order traversal visits nodes in ascending order. Therefore, the kth smallest element can be found by performing an in-order traversal and stopping at the kth node.

// Approaches:
// In-Order Traversal (Recursive):

// Perform an in-order traversal of the BST.

// Keep track of the number of nodes visited.

// When the count reaches k, return the current node's value.

// In-Order Traversal (Iterative):

// Use a stack to simulate the in-order traversal iteratively.

// This approach avoids recursion and is more space-efficient in some cases.

// Augmented BST:

// If the BST is frequently queried for the kth smallest element, we can augment the tree by storing the size of the left subtree at each node. This allows us to find the kth smallest element in 
// O
// (
// log
// ⁡
// n
// )
// O(logn) time.

// Solution Code (Recursive In-Order Traversal):
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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int count = 0;
        inOrder(root, k, count, result);
        return result;
    }

private:
    void inOrder(TreeNode* node, int k, int& count, int& result) {
        if (!node) return;

        // Traverse the left subtree
        inOrder(node->left, k, count, result);

        // Process the current node
        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        // Traverse the right subtree
        inOrder(node->right, k, count, result);
    }
};
// Explanation:
// In-Order Traversal:

// The inOrder function recursively traverses the BST in the order: left subtree → current node → right subtree.

// This ensures that nodes are visited in ascending order.

// Count:

// The count variable keeps track of the number of nodes visited so far.

// When count equals k, the current node's value is the kth smallest element.

// Result:

// The result variable stores the kth smallest value and is returned once found.

// Solution Code (Iterative In-Order Traversal):
// cpp
// Copy
#include <stack>
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* current = root;
        int count = 0;

        while (current || !stack.empty()) {
            // Traverse to the leftmost node
            while (current) {
                stack.push(current);
                current = current->left;
            }

            // Process the current node
            current = stack.top();
            stack.pop();
            count++;
            if (count == k) {
                return current->val;
            }

            // Move to the right subtree
            current = current->right;
        }

        return -1; // If k is invalid
    }
};
// Explanation:
// Stack Usage:

// The stack is used to simulate the recursion in the in-order traversal.

// Nodes are pushed onto the stack as we traverse to the leftmost node.

// Processing Nodes:

// When we pop a node from the stack, it is the next node in the in-order sequence.

// We increment the count and check if it equals k.

// Efficiency:

// The time complexity is 
// O
// (
// n
// )
// O(n) in the worst case (skewed tree), but it is efficient for balanced trees.

// Key Points:
// Both recursive and iterative approaches work well for this problem.

// The recursive approach is simpler to implement but may lead to stack overflow for large trees.

// The iterative approach is more space-efficient and avoids recursion.

// Both solutions are valid and can be used depending on the problem constraints and implementation preferences.