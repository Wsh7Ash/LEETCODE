/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*, TreeNode*> pmap;
            buildParentMap(root, nullptr, pmap);
    
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(target);
            visited.insert(target);
    
            int d = 0;
            vector<int> res;
    
            while(!q.empty()){
                int size = q.size();
                if(d == k){
                    for(int i = 0; i < size; i++){
                        TreeNode* node = q.front();
                        q.pop();
                        res.push_back(node->val);
                    }
                    return res;
                }
                for(int i = 0; i < size; i++){
                    TreeNode* cur = q.front();
                    q.pop();
    
                    if(cur->left && visited.find(cur->left) == visited.end()){
                        visited.insert(cur->left);
                        q.push(cur->left);
                    }
    
                    if(cur->right && visited.find(cur->right) == visited.end()){
                        visited.insert(cur->right);
                        q.push(cur->right);
                    }
                    TreeNode* parent = pmap[cur];
                    if(parent && visited.find(parent) == visited.end()){
                        visited.insert(parent);
                        q.push(parent);
                    }
                }
                d++;
            }
            return res;
        }
    
        void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode* , TreeNode*>& pmap){
            if(!node) return;
            pmap[node] = parent;
            buildParentMap(node->left, node, pmap);
            buildParentMap(node->right, node, pmap);
        }
    };