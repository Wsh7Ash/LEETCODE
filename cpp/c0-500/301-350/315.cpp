#include <vector>

class Solution {
private:
    struct Node {
        int val;
        int count;    // Number of nodes in left subtree
        int dupCount; // Number of duplicates of this value
        Node* left;
        Node* right;
        
        Node(int v) : val(v), count(0), dupCount(1), left(nullptr), right(nullptr) {}
    };
    
    int insert(Node*& root, int val) {
        if (!root) {
            root = new Node(val);
            return 0;
        }
        
        if (val == root->val) {
            root->dupCount++;
            return root->count;
        }
        else if (val < root->val) {
            root->count++;
            return insert(root->left, val);
        }
        else {
            return root->count + root->dupCount + insert(root->right, val);
        }
    }
    
    void deleteTree(Node* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> counts(n);
        Node* root = nullptr;
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            counts[i] = insert(root, nums[i]);
        }
        
        // Clean up memory
        deleteTree(root);
        return counts;
    }
};
Let's break down how this works:

Approach:
Build a BST from right to left
Each node tracks:
Value
Count of nodes in left subtree (smaller numbers)
Count of duplicates
When inserting, count smaller numbers encountered
Key Logic:
Process array backwards
For each number:
If less than current node: go left
If equal: add left count
If greater: add left count + duplicates + recurse right
BST Properties:
Left subtree has smaller values
Right subtree has larger values
Maintains count of smaller elements
Here's a test program:

cpp
Wrap
Copy
#include <iostream>
#include <vector>

class Solution {
    // ... (same implementation as above)
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> nums1 = {5, 2, 6, 1};
    std::cout << "Test 1: ";
    printVector(solution.countSmaller(nums1));
    
    // Test case 2
    std::vector<int> nums2 = {-1};
    std::cout << "Test 2: ";
    printVector(solution.countSmaller(nums2));
    
    // Test case 3
    std::vector<int> nums3 = {-1, -1};
    std::cout << "Test 3: ";
    printVector(solution.countSmaller(nums3));
    
    return 0;
}
Expected Output:

text
Wrap
Copy
Test 1: [2,1,1,0]
Test 2: [0]
Test 3: [0,0]
Complexity:

Time: O(n log n) average case, O(n²) worst case (skewed tree)
Space: O(n) for the BST and output array
Key Features:

Handles duplicates correctly
Works with all constraints:
1 ≤ nums.length ≤ 10^5
-10^4 ≤ nums[i] ≤ 10^4
Properly counts smaller elements to the right
Cleans up allocated memory
Example 1 Walkthrough:

nums = [5,2,6,1]
From right to left:
1: [] → count=0
6: [1] → count=1
2: [1,6] → count=1
5: [1,2,6] → count=2
Result: [2,1,1,0]
Note: For better worst-case performance (O(n log n)), we could use a self-balancing BST or merge sort approach, but this BST solution is simpler to understand and works well for most practical cases while still meeting the constraints.

Optimized Approach: Using a Self-Balancing BST (AVL Tree)
To avoid the TLE issue, we can use a self-balancing BST, such as an AVL tree, which ensures that the tree remains balanced, maintaining the time complexity of insertions and queries at O(log n).

Here’s how you can modify your solution to use an AVL tree:

cpp
Copy
#include <vector>
#include <algorithm>

class Solution {
private:
    struct Node {
        int val;
        int count;    // Number of nodes in left subtree
        int dupCount; // Number of duplicates of this value
        int height;   // Height of the node
        Node* left;
        Node* right;
        
        Node(int v) : val(v), count(0), dupCount(1), height(1), left(nullptr), right(nullptr) {}
    };
    
    int getHeight(Node* node) {
        if (!node) return 0;
        return node->height;
    }
    
    int getBalance(Node* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        
        y->count = (y->left ? y->left->count + y->left->dupCount : 0);
        x->count = (x->left ? x->left->count + x->left->dupCount : 0);
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        
        x->count = (x->left ? x->left->count + x->left->dupCount : 0);
        y->count = (y->left ? y->left->count + y->left->dupCount : 0);
        
        return y;
    }
    
    int insert(Node*& root, int val) {
        if (!root) {
            root = new Node(val);
            return 0;
        }
        
        int count = 0;
        
        if (val == root->val) {
            root->dupCount++;
            count = root->count;
        }
        else if (val < root->val) {
            root->count++;
            count = insert(root->left, val);
        }
        else {
            count = root->count + root->dupCount + insert(root->right, val);
        }
        
        root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
        
        int balance = getBalance(root);
        
        // Left Left Case
        if (balance > 1 && val < root->left->val) {
            root = rightRotate(root);
        }
        
        // Right Right Case
        if (balance < -1 && val > root->right->val) {
            root = leftRotate(root);
        }
        
        // Left Right Case
        if (balance > 1 && val > root->left->val) {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        
        // Right Left Case
        if (balance < -1 && val < root->right->val) {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        
        return count;
    }
    
    void deleteTree(Node* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> counts(n);
        Node* root = nullptr;
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            counts[i] = insert(root, nums[i]);
        }
        
        // Clean up memory
        deleteTree(root);
        return counts;
    }
};
Explanation:
AVL Tree Balancing: The insert function now includes AVL tree balancing logic. After inserting a node, the tree is checked for balance, and rotations are performed if necessary to maintain the AVL property.

Height and Balance Factor: The getHeight and getBalance functions are used to calculate the height and balance factor of a node, respectively.

Rotations: The rightRotate and leftRotate functions perform the necessary rotations to balance the tree.

Time Complexity:
Insertion: O(log n) for each element, as the AVL tree ensures the height is logarithmic.

Overall: O(n log n) for the entire array.

This should resolve the TLE issue by ensuring the tree remains balanced, even for worst-case input scenarios.