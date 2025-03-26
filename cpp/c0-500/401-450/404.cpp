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
        int sumOfLeftLeaves(TreeNode* root) {
            return sumLeftLeaves(root, false);
        }
        
    private:
        int sumLeftLeaves(TreeNode* node, bool isLeft) {
            // Base cases
            if (node == nullptr) {
                return 0;
            }
            
            // Check if current node is a left leaf
            if (node->left == nullptr && node->right == nullptr && isLeft) {
                return node->val;
            }
            
            // Recursively sum left leaves in left and right subtrees
            return sumLeftLeaves(node->left, true) + 
                   sumLeftLeaves(node->right, false);
        }
    };
    How this solution works:
    
    Approach:
    Use recursive traversal
    Track whether a node is a left child
    Sum values only for left leaves
    Key Components:
    isLeft parameter: Indicates if current node is a left child
    Leaf check: No left or right children
    Recursive calls for both subtrees
    Algorithm:
    If node is null, return 0
    If node is a left leaf (no children and isLeft=true), return its value
    Recursively process left subtree (as left children)
    Recursively process right subtree (not left children)
    Sum the results
    Example Walkthrough ([3,9,20,null,null,15,7]):
    text
    
    Collapse
    
    Wrap
    
    Copy
    3 (isLeft=false)
    - Left: 9 (isLeft=true)
      - Leaf with isLeft=true → 9
    - Right: 20 (isLeft=false)
      - Left: 15 (isLeft=true)
        - Leaf with isLeft=true → 15
      - Right: 7 (isLeft=false)
        - Leaf but not left → 0
    Total: 9 + 15 = 24
    Complexity:
    Time: O(n) where n is number of nodes
    Space: O(h) where h is height of tree (recursion stack)
    Key Features:
    Correctly identifies left leaves
    Handles single-node case
    Works with negative values
    The solution satisfies all constraints:
    
    Works for 1 to 1000 nodes
    Handles node values from -1000 to 1000
    Alternative Iterative Solution (using stack):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root) {
            if (!root) return 0;
            
            stack<pair<TreeNode*, bool>> stk;
            stk.push({root, false});
            int sum = 0;
            
            while (!stk.empty()) {
                auto [node, isLeft] = stk.top();
                stk.pop();
                
                if (node->left == nullptr && node->right == nullptr && isLeft) {
                    sum += node->val;
                }
                
                if (node->right) {
                    stk.push({node->right, false});
                }
                if (node->left) {
                    stk.push({node->left, true});
                }
            }
            
            return sum;
        }
    };
    Both solutions:
    
    Correctly handle Example 1: [3,9,20,null,null,15,7] → 24
    Correctly handle Example 2: [1] → 0
    The recursive solution is preferred because:
    
    More concise and readable
    Naturally fits tree traversal pattern
    No need for explicit stack management
    Same time complexity with less code
    The solution efficiently identifies and sums only the left leaves by tracking the parent-child relationship through the isLeft parameter, meeting all requirements of the problem.