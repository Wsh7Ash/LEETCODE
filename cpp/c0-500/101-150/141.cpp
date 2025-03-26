#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // If the list is empty or has only one node, no cycle.

        ListNode *slow = head;  // Slow pointer moves one step at a time
        ListNode *fast = head;  // Fast pointer moves two steps at a time

        while (fast && fast->next) {
            slow = slow->next;       // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps

            if (slow == fast) return true; // Cycle detected
        }

        return false; // No cycle detected
    }
};

// Helper function to create a cycle in a linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* cycleNode = head;
    ListNode* tail = head;
    int index = 0;

    while (tail->next) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode; // Create the cycle
}

// Helper function to print the result
void testCycleDetection(vector<int> values, int pos) {
    if (values.empty()) {
        cout << "List is empty: No cycle\n";
        return;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    createCycle(head, pos); // Creating a cycle in the linked list

    Solution solution;
    bool result = solution.hasCycle(head);

    cout << (result ? "Cycle detected\n" : "No cycle\n");
}

int main() {
    testCycleDetection({3, 2, 0, -4}, 1); // Expected output: Cycle detected
    testCycleDetection({1, 2}, 0);        // Expected output: Cycle detected
    testCycleDetection({1}, -1);          // Expected output: No cycle
    testCycleDetection({}, -1);           // Expected output: List is empty: No cycle

    return 0;
}
