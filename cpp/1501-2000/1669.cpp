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
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* prevA = nullptr;
            ListNode* afterB = nullptr;
            ListNode* cur = list1;
            for(int i = 0; i < a - 1; i++){
                cur = cur->next;
            }
            prevA = cur;
            cur = prevA;
            for(int i = a - 1; i <= b; i++){
                cur = cur->next;
            }
            afterB = cur;
            prevA->next = list2;
            ListNode* list2End = list2;
            while(list2End->next != nullptr){
                list2End = list2End->next;
            }
            list2End->next = afterB;
            return list1;
        }
    };