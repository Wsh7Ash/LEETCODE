// To determine if a singly linked list is a palindrome, we can use the following approach:

// Approach:
// Find the Middle of the Linked List:

// Use the slow and fast pointer technique to find the middle of the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end, the slow pointer will be at the middle.

// Reverse the Second Half of the Linked List:

// Reverse the second half of the linked list starting from the middle node.

// Compare the First Half and the Reversed Second Half:

// Traverse both halves simultaneously and compare the values. If all values match, the linked list is a palindrome.

// Restore the Linked List (Optional):

// If required, reverse the second half again to restore the original linked list.

// Solution Code:
// cpp
// Copy
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true; // Empty list or single node is a palindrome
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
// Explanation:
// Finding the Middle:

// The slow pointer moves one step at a time, and the fast pointer moves two steps at a time. When the fast pointer reaches the end, the slow pointer will be at the middle of the linked list.

// Reversing the Second Half:

// We reverse the second half of the linked list starting from the middle node. This allows us to compare the first half with the reversed second half.

// Comparing the Halves:

// We traverse both halves simultaneously and compare the values. If all values match, the linked list is a palindrome.

// Restoring the Linked List (Optional):

// If the original linked list needs to be preserved, we can reverse the second half again after comparison.

// Example Walkthrough:
// Example 1:
// Input: head = [1, 2, 2, 1]

// Output: true

// Execution:
// Find the Middle:

// Slow pointer stops at the second 2.

// Reverse the Second Half:

// The second half [2, 1] becomes [1, 2].

// Compare the Halves:

// First half: [1, 2]

// Reversed second half: [1, 2]

// All values match, so the linked list is a palindrome.

// Example 2:
// Input: head = [1, 2]

// Output: false

// Execution:
// Find the Middle:

// Slow pointer stops at 2.

// Reverse the Second Half:

// The second half [2] remains [2].

// Compare the Halves:

// First half: [1]

// Reversed second half: [2]

// Values do not match, so the linked list is not a palindrome.

// Key Points:
// The solution uses the slow and fast pointer technique to find the middle of the linked list.

// Reversing the second half allows us to compare it with the first half.

// The time complexity is 
// O
// (
// n
// )
// O(n), and the space complexity is 
// O
// (
// 1
// )
// O(1).