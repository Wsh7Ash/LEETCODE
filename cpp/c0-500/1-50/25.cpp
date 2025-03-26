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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode ln;
        ln.next = head;
        ListNode *prev = &ln;
        ListNode *current = head;
        ListNode *next = nullptr;

        int length = 0;
        while(current){
            length++;
            current = current->next;
        }
        current = head;
        while(length >= k){
            ListNode* tail = current;
            ListNode* prevGroup = prev;

            for(int i = 0; i < k; i++){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            prevGroup->next = prev;
            tail->next = current;

            prev = tail;
            length -= k;
        }

        return ln.next;
    }
};