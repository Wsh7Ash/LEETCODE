#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr; // No cycle if the list is empty or has only one node
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect the cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected
                break;
            }
        }

        // Step 2: Check if there is no cycle
        if (!fast || !fast->next) {
            return nullptr; // No cycle
        }

        // Step 3: Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Node where the cycle begins
    }
};