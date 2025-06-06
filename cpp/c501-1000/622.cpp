class MyCircularQueue {
    public:
        vector<int> data;
        int head;
        int tail;
        int size;
        int capacity;
        MyCircularQueue(int k) {
            data.resize(k);
            head = -1;
            tail = -1;
            size = 0;
            capacity = k;
        }
        
        bool enQueue(int value) {
            if(isFull()){
                return false;
            }
            if(isEmpty()){
                head = 0;
            }
            tail = (tail + 1) % capacity;
            data[tail] = value;
            size++;
            return true;
        }
        
        bool deQueue() {
            if(isEmpty()) return false;
            if(head == tail){
                head = -1;
                tail = -1;
            }else{
                head = (head + 1) % capacity;
            }
            size--;
            return true;
        }
        
        int Front() {
            if(isEmpty()) return -1;
            return data[head];
        }
        
        int Rear() {
            if(isEmpty()) return -1;
            return data[tail];        
        }
        
        bool isEmpty() {
            return size == 0;
        }
        
        bool isFull() {
            return size == capacity;
        }
    };
    
    /**
     * Your MyCircularQueue object will be instantiated and called as such:
     * MyCircularQueue* obj = new MyCircularQueue(k);
     * bool param_1 = obj->enQueue(value);
     * bool param_2 = obj->deQueue();
     * int param_3 = obj->Front();
     * int param_4 = obj->Rear();
     * bool param_5 = obj->isEmpty();
     * bool param_6 = obj->isFull();
     */