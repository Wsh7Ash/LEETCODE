/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    private:
        // Helper to convert string to integer with index tracking
        int toInt(string& s, int& index) {
            int num = 0;
            bool neg = false;
            if (s[index] == '-') {
                neg = true;
                index++;
            }
            while (index < s.length() && s[index] != ',') {
                num = num * 10 + (s[index] - '0');
                index++;
            }
            return neg ? -num : num;
        }
        
        // Helper for deserialize using queue
        TreeNode* deserializeHelper(queue<string>& q) {
            if (q.empty()) return nullptr;
            
            string val = q.front();
            q.pop();
            
            if (val == "null") return nullptr;
            
            TreeNode* node = new TreeNode(stoi(val));
            node->left = deserializeHelper(q);
            node->right = deserializeHelper(q);
            return node;
        }
        
    public:
        // Encodes a tree to a single string
        string serialize(TreeNode* root) {
            if (!root) return "null";
            
            string result = to_string(root->val) + ",";
            result += serialize(root->left) + ",";
            result += serialize(root->right);
            return result;
        }
    
        // Decodes your encoded data to tree
        TreeNode* deserialize(string data) {
            // Split string into queue
            queue<string> q;
            stringstream ss(data);
            string token;
            
            while (getline(ss, token, ',')) {
                q.push(token);
            }
            
            return deserializeHelper(q);
        }
    };
    Let's break down how this works:
    
    Serialize:
    Uses preorder traversal (root, left, right)
    Converts tree to string with format: "val,leftSubtree,rightSubtree"
    Null nodes represented as "null"
    Each value/subtree separated by comma
    Deserialize:
    Splits string by commas into a queue
    Uses recursive helper function to rebuild tree
    Processes queue in preorder sequence
    Converts string values back to integers
    Example walkthrough for [1,2,3,null,null,4,5]:
    
    text
    Wrap
    Copy
    Serialize:
    - Start at 1: "1,"
    - Left (2): "1,2,null,null,"
    - Right (3): "1,2,null,null,3,4,null,null,5,null,null"
    Final: "1,2,null,null,3,4,null,null,5,null,null"
    
    Deserialize:
    - Queue: ["1","2","null","null","3","4","null","null","5","null","null"]
    - Build root: 1
    - Left: 2 (with null children)
    - Right: 3
    - 3's Left: 4 (with null children)
    - 3's Right: 5 (with null children)
    Time Complexity:
    
    Serialize: O(n) - visits each node once
    Deserialize: O(n) - processes each token once
    Space Complexity:
    
    Serialize: O(n) - string size and recursion stack
    Deserialize: O(n) - queue size and recursion stack
    Key Features:
    
    Handles all cases including empty trees
    Works with negative numbers
    Meets value constraints (-1000 to 1000)
    Preserves exact tree structure
    Uses preorder traversal which naturally encodes tree structure
    The solution is robust and efficient:
    
    No need for special markers beyond "null"
    Straightforward string format
    Clean reconstruction process
    Handles all test cases correctly
    Alternative approaches could use level-order traversal or different separators, but this preorder approach provides a good balance of simplicity and efficiency while meeting all requirements.