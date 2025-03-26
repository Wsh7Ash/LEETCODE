ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ln = new ListNode();
        ListNode* cur = ln;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int digit = sum % 10;

            cur->next = new ListNode(digit);
            cur = cur->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return ln->next;
    }