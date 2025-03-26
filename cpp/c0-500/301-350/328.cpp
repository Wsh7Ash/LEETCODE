Let's solve the "Odd Even Linked List" problem in C++. We'll use a two-pointer approach to achieve O(1) space complexity while maintaining O(n) time complexity.

Here's the solution:

cpp
Wrap
Copy
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Handle empty list or single node
        if (!head || !head->next) return head;
        
        // Initialize pointers
        ListNode* odd = head;          // Points to odd indexed nodes
        ListNode* even = head->next;   // Points to even indexed nodes
        ListNode* evenHead = even;     // Save even list head to connect later
        
        // While there are nodes to process
        while (even && even->next) {
            // Connect odd node to next odd node (skip even)
            odd->next = even->next;
            odd = odd->next;
            
            // Connect even node to next even node (skip odd)
            even->next = odd->next;
            even = even->next;
        }
        
        // Connect odd list to even list
        odd->next = evenHead;
        
        return head;
    }
};

// Test code
#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1: [1,2,3,4,5]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1 = solution.oddEvenList(head1);
    printList(head1);  // Output: 1 3 5 2 4
    
    // Test case 2: [2,1,3,5,6,4,7]
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(5);
    head2->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next = new ListNode(4);
    head2->next->next->next->next->next->next = new ListNode(7);
    head2 = solution.oddEvenList(head2);
    printList(head2);  // Output: 2 3 6 7 1 5 4
    
    return 0;
}
How it works:

Base Cases:
If list is empty or has one node, return as is
Two Pointers:
odd: Points to current odd-indexed node
even: Points to current even-indexed node
evenHead: Saves start of even list for later connection
Algorithm:
While there are pairs of nodes to process:
Connect odd->next to next odd node (skip even)
Connect even->next to next even node (skip odd)
Move both pointers forward
Finally connect odd list tail to even list head
Example Walkthrough for [1,2,3,4,5]:
Initial: 1->2->3->4->5
Step 1: 1->3, 2->4, odd=3, even=4
Step 2: 1->3->5, 2->4, odd=5, even=null
Final: 1->3->5->2->4
Complexity:

Time Complexity: O(n) - single pass through the list
Space Complexity: O(1) - only using a constant number of pointers
The solution satisfies all constraints:

Works for lists of size 0 to 10^4
Handles node values from -10^6 to 10^6
Maintains relative order within odd and even groups
Uses no extra space beyond a few pointers
Processes each node exactly once
The output preserves the original ordering within each group:

Odd indices (1st,3rd,5th...) come first
Even indices (2nd,4th,6th...) follow
Original relative order is maintained within each group