#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head; // If list is empty or has one element, return as is.

        ListNode* dummy = new ListNode(0); // Dummy node for easier insertions
        ListNode* curr = head;  // Current node to be inserted

        while (curr) {
            ListNode* prev = dummy;  // Start at dummy node
            ListNode* next = curr->next;  // Store next node before modifying curr
            
            // Find insertion position
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to next node
            curr = next;
        }

        return dummy->next; // Return the sorted list head
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Driver Code
int main() {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createList(arr, n);
    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.insertionSortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
