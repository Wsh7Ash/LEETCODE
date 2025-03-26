#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Recursive Preorder Traversal
    void preorderRecursive(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorderRecursive(root->left, result);
        preorderRecursive(root->right, result);
    }

    vector<int> preorderTraversalRecursive(TreeNode* root) {
        vector<int> result;
        preorderRecursive(root, result);
        return result;
    }

    // Iterative Preorder Traversal using Stack
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);

            // Push right child first so that left child is processed first
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;
    }
};

// Helper function to build a tree from an array representation
TreeNode* buildTree(vector<int> values) {
    if (values.empty()) return nullptr;
    
    vector<TreeNode*> nodes;
    for (int val : values) {
        nodes.push_back(val != -1 ? new TreeNode(val) : nullptr);
    }

    int n = values.size();
    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int leftIdx = 2 * i + 1;
            int rightIdx = 2 * i + 2;
            if (leftIdx < n) nodes[i]->left = nodes[leftIdx];
            if (rightIdx < n) nodes[i]->right = nodes[rightIdx];
        }
    }

    return nodes[0];
}

int main() {
    vector<int> values = {1, -1, 2, -1, -1, 3}; // Example 1
    TreeNode* root = buildTree(values);

    Solution solution;
    
    vector<int> resultRecursive = solution.preorderTraversalRecursive(root);
    vector<int> resultIterative = solution.preorderTraversalIterative(root);

    cout << "Recursive Preorder: ";
    for (int num : resultRecursive) cout << num << " ";
    cout << endl;

    cout << "Iterative Preorder: ";
    for (int num : resultIterative) cout << num << " ";
    cout << endl;

    return 0;
}
