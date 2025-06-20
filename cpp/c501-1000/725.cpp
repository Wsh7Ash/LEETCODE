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
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
           vector<ListNode*> parts(k, nullptr);
           int l = 0;
           ListNode* cur = head;
           while(cur){
            l++;
            cur = cur->next;
           } 
           int bs = l / k;
           int e = l % k;
    
           cur = head;
           for(int i = 0; i < k && cur; i++){
            parts[i] = cur;
            int part_size = bs + (e > 0 ? 1 : 0);
            e--;
            for(int j = 1; j < part_size; j++){
                cur = cur->next;
            }
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
           }
           return parts;
        }
    };