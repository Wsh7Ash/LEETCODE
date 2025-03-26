class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode *lessHead = new ListNode(0), *greaterHead = new ListNode(0);
            ListNode *less = lessHead, *greater = greaterHead;
    
            while (head) {
                if (head->val < x) {
                    less->next = head;
                    less = less->next;
                } else {
                    greater->next = head;
                    greater = greater->next;
                }
                head = head->next;
            }
    
            greater->next = nullptr;  // Mark end of greater list
            less->next = greaterHead->next;  // Connect two lists
    
            return lessHead->next;
        }
    };
    