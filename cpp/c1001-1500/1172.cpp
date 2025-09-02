class DinnerPlates {
    private:
        int cap;
        vector<vector<int>> stacks;
        priority_queue<int, vector<int>, greater<int>> available;
        int rightmost;
    
    public:
        DinnerPlates(int capacity) : cap(capacity), rightmost(-1) {
            
        }
        
        void push(int val) {
            while(!available.empty() && available.top() >= stacks.size()) available.pop();
    
            if(available.empty()){
                stacks.push_back({});
                available.push(stacks.size() - 1);
            }
    
            int index = available.top();
            stacks[index].push_back(val);
    
            rightmost = max(rightmost, index);
    
            if(stacks[index].size() == cap) available.pop();
        }
        
        int pop() {
            while(rightmost >= 0 && stacks[rightmost].empty()) rightmost--;
    
            if(rightmost == -1) return -1;
    
            return popAtStack(rightmost);
        }
        
        int popAtStack(int index) {
            if(index >= stacks.size() || stacks[index].empty()) return -1;
    
            int val = stacks[index].back();
            stacks[index].pop_back();
    
            if(stacks[index].size() == cap - 1) available.push(index);
    
            return val;
        }
    };
    
    /**
     * Your DinnerPlates object will be instantiated and called as such:
     * DinnerPlates* obj = new DinnerPlates(capacity);
     * obj->push(val);
     * int param_2 = obj->pop();
     * int param_3 = obj->popAtStack(index);
     */