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
        ListNode* swapNodes(ListNode* head, int k) {
            ListNode* first = head;
            for(int i = 1; i < k; i++){
                first = first->next;
            }
            ListNode* sec = head;
            ListNode* temp = first;
            while(temp->next != nullptr){
                temp = temp->next;
                sec = sec->next;
            }
            int tempVal = first->val;
            first->val = sec->val;
            sec->val = tempVal;
            return head;
        }
    };