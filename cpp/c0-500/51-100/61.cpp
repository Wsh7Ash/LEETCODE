struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head; // No rotation needed
        }

        // Step 1: Find the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Calculate the effective number of rotations
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed
        }

        // Step 3: Find the new tail and new head
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        // Step 4: Perform the rotation
        newTail->next = nullptr; // Break the list at the new tail
        tail->next = head; // Connect the original tail to the original head

        return newHead; // Return the new head
    }
};

int main() {
    // Example 1
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution solution;
    ListNode* result1 = solution.rotateRight(head1, 2);

    // Print the result
    while (result1) {
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << std::endl;

    // Example 2
    ListNode* head2 = new ListNode(0, new ListNode(1, new ListNode(2)));
    ListNode* result2 = solution.rotateRight(head2, 4);

    // Print the result
    while (result2) {
        std::cout << result2->val << " ";
        result2 = result2->next;
    }
    std::cout << std::endl;

    return 0;
}