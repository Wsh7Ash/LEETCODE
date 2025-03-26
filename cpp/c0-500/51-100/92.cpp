#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Create a dummy node to simplify edge cases when left is 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        // Move `pre` to the node just before the `left`-th node
        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }

        // `start` is the node at position `left`
        ListNode* start = pre->next;
        // `then` is the node that will be reversed
        ListNode* then = start->next;

        // Perform the reversal
        for (int i = 0; i < right - left; i++) {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
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

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example 1: Input: [1, 2, 3, 4, 5], left = 2, right = 4
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.reverseBetween(head1, 2, 4);
    printList(result1);  // Output: [1, 4, 3, 2, 5]

    // Example 2: Input: [5], left = 1, right = 1
    ListNode* head2 = createList({5});
    ListNode* result2 = solution.reverseBetween(head2, 1, 1);
    printList(result2);  // Output: [5]

    return 0;
}
