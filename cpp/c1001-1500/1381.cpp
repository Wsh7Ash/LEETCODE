class CustomStack {
    private:
        vector<int> stack;
        vector<int> inc;
        int maxSize;
        int size;
    
    public:
        CustomStack(int maxSize) {
            this->maxSize = maxSize;
            this->size = 0;
            stack.resize(maxSize);
            inc.resize(maxSize, 0);
        }
        
        void push(int x) {
            if(size < maxSize){
                stack[size] = x;
                size++;
            }
        }
        
        int pop() {
            if(size == 0) return -1;
    
            int res = stack[size - 1] + inc[size - 1];
            if(size > 1){
                inc[size - 2] += inc[size - 1];
            }
            inc[size - 1] = 0;
            size--;
    
            return res;
        }
        
        void increment(int k, int val) {
            if(size == 0) return;
    
            int idx = min(k, size) - 1;
            inc[idx] += val;
        }
    };
    
    /**
     * Your CustomStack object will be instantiated and called as such:
     * CustomStack* obj = new CustomStack(maxSize);
     * obj->push(x);
     * int param_2 = obj->pop();
     * obj->increment(k,val);
     */