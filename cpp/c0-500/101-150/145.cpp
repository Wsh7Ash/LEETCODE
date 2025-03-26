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
    // Recursive Postorder Traversal
    void postorderRecursive(TreeNode* root, vector<int>& result) {
        if (!root) return;
        postorderRecursive(root->left, result);
        postorderRecursive(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversalRecursive(TreeNode* root) {
        vector<int> result;
        postorderRecursive(root, result);
        return result;
    }

    // Iterative Postorder Traversal using Two Stacks
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
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
    
    vector<int> resultRecursive = solution.postorderTraversalRecursive(root);
    vector<int> resultIterative = solution.postorderTraversalIterative(root);

    cout << "Recursive Postorder: ";
    for (int num : resultRecursive) cout << num << " ";
    cout << endl;

    cout << "Iterative Postorder: ";
    for (int num : resultIterative) cout << num << " ";
    cout << endl;

    return 0;
}
