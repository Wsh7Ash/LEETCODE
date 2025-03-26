#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        // Find the middle element of the list and make it the root
        return sortedListToBSTHelper(head);
    }
    
private:
    // Helper function to recursively build the tree
    TreeNode* sortedListToBSTHelper(ListNode*& head) {
        if (!head) return nullptr;

        // Find the middle node using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Move slow by 1 step and fast by 2 steps
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        // If there is a previous node, disconnect the left part of the list
        if (prev) {
            prev->next = nullptr;
        }
        
        // The middle element becomes the root
        TreeNode* root = new TreeNode(slow->val);
        
        // Move the head pointer to the next part of the list
        if (head == slow) {
            head = nullptr;  // Edge case: if the list has only one element
        } else {
            head = slow->next;
        }

        // Recursively construct the left and right subtrees
        root->left = sortedListToBSTHelper(head);
        root->right = sortedListToBSTHelper(head);
        
        return root;
    }
};

// Helper function to print the tree in level order (for testing purposes)
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Helper function to create a linked list from an array (for testing purposes)
ListNode* createList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : nums) {
        ListNode* newNode = new ListNode(num);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    // Test case: Sorted linked list [-10, -3, 0, 5, 9]
    vector<int> nums = {-10, -3, 0, 5, 9};
    ListNode* head = createList(nums);

    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);

    // Printing the BST in level order
    printTree(root);  // Expected Output: [0, -3, 9, -10, null, 5]

    return 0;
}
