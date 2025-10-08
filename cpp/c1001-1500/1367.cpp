/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        bool isSubPath(ListNode* head, TreeNode* root) {
            if(!head) return true;
            if(!root) return false;
    
            bool found = dfs(head , root);
            if(found) return true;
    
            if(root->left){
                found = isSubPath(head, root->left);
                if(found) return true;
            }
            if(root->right){
                found = isSubPath(head, root->right);
                if(found) return true;
            }
    
            return false;
        }
    
    private:
        bool dfs(ListNode* head, TreeNode* root){
            if(!head) return true;
            if(!root) return false;
    
            if(head->val != root->val) return false;
    
            return dfs(head->next, root->left) || dfs(head->next, root->right);
    
        }
    };