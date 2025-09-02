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
        ListNode* removeZeroSumSublists(ListNode* head) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
    
            unordered_map<int, ListNode*> prefixSums;
            int prefixSum = 0;
            ListNode* cur = dummy;
    
            while(cur){
                prefixSum += cur->val;
                prefixSums[prefixSum] = cur;
                cur = cur->next;
            }
    
            prefixSum = 0;
            cur = dummy;
            while(cur){
                prefixSum += cur->val;
                cur->next = prefixSums[prefixSum]->next;
                cur = cur->next;
            }
            return dummy->next;
        }
    };