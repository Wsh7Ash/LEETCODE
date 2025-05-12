/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public:
        vector<int> postorderIterative(Node* root){
            vector<int> res;
            if(!root) return res;
            stack<Node*> s;
            s.push(root);
            while(!s.empty()){
                Node* node = s.top();
                s.pop();
                for(Node* child : node->children){
                    s.push(child);
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
    
        void postorderHelper(Node* node, vector<int>& res){
            if(!node) return;
            for(Node* child : node->children){
                postorderHelper(child, res);
            }
            res.push_back(node->val);
        }
        
        vector<int> postorder(Node* root) {
            vector<int> res;
            postorderHelper(root, res);
            return res;
        }
    };