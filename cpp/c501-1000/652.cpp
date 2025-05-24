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
        unordered_map<string, int> subtreeCount;
        vector<TreeNode*> res;
        string serialize(TreeNode* node){
            if(!node) return "null";
            string l = serialize(node->left);
            string r = serialize(node->right);
            string subtree = "(" + l + "," + r + "," + to_string(node->val) + ")";
            subtreeCount[subtree]++;
            if(subtreeCount[subtree] == 2) res.push_back(node);
            return subtree;
        }
        
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            serialize(root);
            return res;
        }
    };