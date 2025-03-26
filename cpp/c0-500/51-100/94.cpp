#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> stack;
        TreeNode* current = root;

        while (current != nullptr || !stack.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            // current is null, pop the top node and process it
            current = stack.top();
            stack.pop();
            result.push_back(current->val);  // Visit the node

            // Now move to the right subtree
            current = current->right;
        }

        return result;
    }
};
