#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;  // If the tree is empty, return null
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process each node at the current level
            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();
                
                // If it's not the last node in the level, set the next pointer
                if (i < levelSize - 1) {
                    current->next = q.front();
                }
                
                // Add the left and right children to the queue for the next level
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
        
        return root;  // Return the root with all next pointers set
    }
};

void printTree(Node* root) {
    if (!root) return;
    
    Node* level_start = root;
    
    while (level_start) {
        Node* current = level_start;
        
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        
        cout << "# ";  // Indicate end of the current level
        level_start = level_start->left;  // Move to the next level
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Example 1: Create the tree [1,2,3,4,5,null,7]
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    
    sol.connect(root);
    printTree(root);  // Expected output: 1 # 2 3 # 4 5 7 #
    
    // Example 2: Empty tree
    root = nullptr;
    sol.connect(root);
    printTree(root);  // Expected output: (Nothing)
    
    return 0;
}
