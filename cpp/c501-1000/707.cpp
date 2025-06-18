class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* head;
    int size;
    MyLinkedList() : head(nullptr), size(0) {}
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        ListNode* cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if(size == 0){
            addAtHead(val);
            return;
        }
        ListNode* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = new ListNode(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        ListNode* cur = head;
        for(int i = 0; i < index - 1; i++){
            cur = cur->next;
        }
        ListNode* newNode =new ListNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0){
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            return;
        }
        ListNode* cur = head;
        for(int i = 0; i < index - 1; i++){
            cur = cur->next;
        }
        ListNode* toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */