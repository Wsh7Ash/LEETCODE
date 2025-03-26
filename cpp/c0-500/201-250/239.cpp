#include <iostream>
#include <vector>
#include <deque>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root; // If p and q are found in different subtrees
        
        return left ? left : right; // Return non-null subtree (either left or right)
    }
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListSolution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return;
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

class ArraySolution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1);
        
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = left_product;
            left_product *= nums[i];
        }
        
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= right_product;
            right_product *= nums[i];
        }
        
        return result;
    }
};

class SlidingWindowSolution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq;  // stores indices of potential max elements
        std::vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove indices whose corresponding values are less than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Append the maximum element (at front) to the result once the first window is complete
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
// Explanation of the Sliding Window Maximum:
// Deque Usage: We maintain a deque (dq) that stores indices in decreasing order of their corresponding values. This ensures that the front of the deque always has the index of the maximum element for the current window.
// Window Maintenance: For each index i, if the index at the front of the deque is out of the current window (i - k), it’s removed.
// Maintaining Order: We remove indices from the back of the deque as long as their corresponding values are less than nums[i].
// Result Formation: Once we have processed at least k elements (i.e., when i >= k - 1), the element at the front of the deque is the maximum for that window and is added to the result.