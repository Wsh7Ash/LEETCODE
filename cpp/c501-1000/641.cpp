class MyCircularDeque {
    public:
        vector<int> buffer;
        int cap;
        int size;
        int front;
        int rear;
    
        MyCircularDeque(int k) {
            cap = k;
            buffer.resize(k);
            size = 0;
            front = 0;
            rear = k - 1;    
        }
        
        bool insertFront(int value) {
            if(isFull()) return false;
            front = (front - 1 + cap) % cap;
            buffer[front] = value;
            size++;
            return true;
        }
        
        bool insertLast(int value) {
            if(isFull()) return false;
            rear = (rear + 1) % cap;
            buffer[rear] = value;
            size++;
            return true;
        }
        
        bool deleteFront() {
            if(isEmpty()) return false;
            front = (front + 1) % cap;
            size--;
            return true;
        }
        
        bool deleteLast() {
            if(isEmpty()) return false;
            rear = (rear - 1 + cap) % cap;
            size--;
            return true;
        }
        
        int getFront() {
            if(isEmpty()) return -1;
            return buffer[front];
        }
        
        int getRear() {
            if(isEmpty()) return -1;
            return buffer[rear];
        }
        
        bool isEmpty() {
            return size == 0;
        }
        
        bool isFull() {
            return size == cap;
        }
    };
    
    /**
     * Your MyCircularDeque object will be instantiated and called as such:
     * MyCircularDeque* obj = new MyCircularDeque(k);
     * bool param_1 = obj->insertFront(value);
     * bool param_2 = obj->insertLast(value);
     * bool param_3 = obj->deleteFront();
     * bool param_4 = obj->deleteLast();
     * int param_5 = obj->getFront();
     * int param_6 = obj->getRear();
     * bool param_7 = obj->isEmpty();
     * bool param_8 = obj->isFull();
     */