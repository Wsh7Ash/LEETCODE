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
            ListNode* ln = head;
            while(ln && ln->next){
                if(ln->val == ln->next->val){
                    ln->next = ln->next->next;
                }else{
                    ln = ln->next;
                }
            }
            return head;
        }
    };