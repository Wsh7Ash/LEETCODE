#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
    
    // Helper function to push all left nodes of the tree starting from root onto the stack
    void pushLeft(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    // Returns true if there are more nodes to visit in the in-order traversal
    bool hasNext() {
        return !st.empty();
    }
    
    // Returns the next smallest number in the in-order traversal
    int next() {
        TreeNode* currNode = st.top();
        st.pop();
        
        // If the current node has a right child, push all its left children onto the stack
        pushLeft(currNode->right);
        
        return currNode->val;
    }
};

// Example usage
int main() {
    // Construct the binary search tree
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Create the BSTIterator object
    BSTIterator iterator(root);
    
    // Iterate over the BST using the iterator
    cout << iterator.next() << endl;  // 3
    cout << iterator.next() << endl;  // 7
    cout << iterator.hasNext() << endl;  // true
    cout << iterator.next() << endl;  // 9
    cout << iterator.hasNext() << endl;  // true
    cout << iterator.next() << endl;  // 15
    cout << iterator.hasNext() << endl;  // true
    cout << iterator.next() << endl;  // 20
    cout << iterator.hasNext() << endl;  // false
    
    return 0;
}
