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
#include <utility>
using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
    
private:
    // Returns pair<withRoot, withoutRoot>
    // withRoot: max money when including current node
    // withoutRoot: max money when excluding current node
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        // Recursively process left and right subtrees
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        
        // If we rob this node, we can't rob its children
        int withRoot = node->val + left.second + right.second;
        
        // If we don't rob this node, we can choose max of with/without for children
        int withoutRoot = max(left.first, left.second) + 
                         max(right.first, right.second);
        
        return {withRoot, withoutRoot};
    }
};

// Test code
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    Solution solution;
    
    // Test case 1: [3,2,3,null,3,null,1]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(1);
    cout << solution.rob(root1) << endl;  // 7
    
    // Test case 2: [3,4,5,1,3,null,1]
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(1);
    cout << solution.rob(root2) << endl;  // 9
    
    return 0;
}
How it works:

DP Approach:
For each node, we track two values:
Maximum money if we rob this node
Maximum money if we don't rob this node
Use pair<withRoot, withoutRoot> to store these values
DFS Logic:
Base case: null node returns {0, 0}
For each node:
If we rob it: take its value + grandchildren's money (children excluded)
If we don't rob it: take max of children's with/without values
Return both possibilities
Key Insight:
Can't rob adjacent nodes (parent and child)
At each node, we need to decide whether to:
Rob current node and skip children
Skip current node and optimize children
Example Walkthrough for [3,4,5,1,3,null,1]:
Leaf 1: {1, 0}
Leaf 3: {3, 0}
Leaf 1: {1, 0}
Node 4: {4+0+0=4, max(1,0)+max(3,0)=4}
Node 5: {5+0=5, max(1,0)=1}
Root 3: {3+4+1=8, max(4,4)+max(5,1)=9}
Result: max(8,9)=9
Complexity:

Time Complexity: O(n) - visit each node once
Space Complexity: O(h) - recursion stack height, where h is tree height
The solution satisfies all constraints:

Works for 1 to 10^4 nodes
Handles values 0 to 10^4
Correctly computes maximum money without robbing adjacent houses
For the examples:

[3,2,3,null,3,null,1] → 7 (3+3+1)
[3,4,5,1,3,null,1] → 9 (4+5)
This solution efficiently computes the maximum robbery amount by:

Using bottom-up information gathering
Avoiding explicit DP array
Making optimal local choices at each node
Handling all tree configurations