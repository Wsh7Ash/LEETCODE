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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;   // Save the next node
            current->next = prev;   // Reverse the current node's pointer
            prev = current;         // Move prev and current one step forward
            current = next;
        }
        
        return prev;  // prev will be the new head of the reversed list
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);
    
    cout << "Reversed List: ";
    printList(reversedHead);  // Output: 5 4 3 2 1
    
    return 0;
}
