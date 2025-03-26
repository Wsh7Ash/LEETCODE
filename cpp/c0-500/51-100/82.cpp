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
        ListNode* deleteDuplicates(ListNode* head) {
            // Dummy node to handle edge cases
            ListNode* dummy = new ListNode(0, head);
            ListNode* prev = dummy; // Points to the last non-duplicate node
            
            while (head) {
                // If the current node has duplicates
                if (head->next && head->val == head->next->val) {
                    // Skip all duplicates
                    while (head->next && head->val == head->next->val) {
                        head = head->next;
                    }
                    prev->next = head->next; // Remove duplicates
                } else {
                    prev = prev->next; // Move prev forward only if no duplicate
                }
                head = head->next; // Move head forward
            }
            
            return dummy->next; // Return the updated list
        }
    };
    