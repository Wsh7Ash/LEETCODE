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
        if (!root) return root;  // If tree is empty, return null
        
        Node* leftmost = root;  // Start with the root
        
        // Traverse each level
        while (leftmost->left) {  // Continue until we reach the last level
            Node* current = leftmost;
            
            // Iterate through the current level
            while (current) {
                current->left->next = current->right;  // Link the left child to the right child
                
                // If there is a next node, link the right child to the next left child
                if (current->next) {
                    current->right->next = current->next->left;
                }
                
                // Move to the next node on the current level
                current = current->next;
            }
            
            // Move to the next level
            leftmost = leftmost->left;
        }
        
        return root;  // Return the root node with all next pointers connected
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
        level_start = level_start->left;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Example 1: Create the tree [1,2,3,4,5,6,7]
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    sol.connect(root);
    printTree(root);  // Expected output: 1 # 2 3 # 4 5 6 7 #
    
    // Example 2: Empty tree
    root = nullptr;
    sol.connect(root);
    printTree(root);  // Expected output: (Nothing)
    
    return 0;
}
