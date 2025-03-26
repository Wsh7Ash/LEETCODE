ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ln = new ListNode();
        ln->next = head;

        ListNode* f = ln;
        ListNode* s = ln;

        for(int i = 0; i < n; i++){
            f = f->next;
        }
        while(f->next != nullptr){
            f = f->next;
            s = s->next;
        }

        ListNode* nodeToRemove = s->next;
        s->next = s->next->next;
        delete nodeToRemove;

        ListNode* newHead = ln->next;
        delete ln;
        return newHead;
    }