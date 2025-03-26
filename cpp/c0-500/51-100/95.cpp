#include <vector>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};  // No tree possible with 0 nodes
        return generateTreesHelper(1, n);
    }
    
private:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> result;
        
        if (start > end) {
            result.push_back(nullptr);  // Base case: no nodes in the subtree
            return result;
        }
        
        // Try each value in the range [start, end] as the root
        for (int rootVal = start; rootVal <= end; ++rootVal) {
            // Recursively generate all left and right subtrees
            vector<TreeNode*> leftSubtrees = generateTreesHelper(start, rootVal - 1);
            vector<TreeNode*> rightSubtrees = generateTreesHelper(rootVal + 1, end);
            
            // Combine left and right subtrees with the root
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
};

// Helper function to print the tree (pre-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;
    int n = 3;
    vector<TreeNode*> trees = solution.generateTrees(n);
    
    cout << "Unique BSTs for n = " << n << ":\n";
    for (TreeNode* tree : trees) {
        printTree(tree);
        cout << endl;
    }
    return 0;
}
