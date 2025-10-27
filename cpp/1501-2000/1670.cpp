class FrontMiddleBackQueue {
    private:
        deque<int> first, second;
        void balance(){
            if(first.size() > second.size() + 1){
                second.push_front(first.back());
                first.pop_back();
            }else if(first.size() < second.size()){
                first.push_back(second.front());
                second.pop_front();
            }
        }
    public:
        FrontMiddleBackQueue() {}
        
        void pushFront(int val) {
            first.push_front(val);
            balance();
        }
        
        void pushMiddle(int val) {
            if(first.size() > second.size()){
                second.push_front(first.back());
                first.pop_back();
            }
            first.push_back(val);
            balance();
        }
        
        void pushBack(int val) {
            second.push_back(val);
            balance();
        }
        
        int popFront() {
            if(first.empty() && second.empty()) return -1;
            int val;
            if(!first.empty()){
                val = first.front();
                first.pop_front();
            }else{
                val = second.front();
                second.pop_front();
            }
            balance();
            return val;
        }
        
        int popMiddle() {
            if(first.empty() && second.empty()) return -1;
            int val;
            if(first.size() == second.size()){
                val = first.back();
                first.pop_back();
            }else{
                val = first.back();
                first.pop_back();
            }
            balance();
            return val;
        }
        
        int popBack() {
            if(first.empty() && second.empty()) return -1;
            int val;
            if(!second.empty()){
                val = second.back();
                second.pop_back();
            }else{
                val = first.back();
                first.pop_back();
            }
            balance();
            return val;
        }
    };
    
    /**
     * Your FrontMiddleBackQueue object will be instantiated and called as such:
     * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
     * obj->pushFront(val);
     * obj->pushMiddle(val);
     * obj->pushBack(val);
     * int param_4 = obj->popFront();
     * int param_5 = obj->popMiddle();
     * int param_6 = obj->popBack();
     */