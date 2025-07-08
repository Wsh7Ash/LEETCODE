class ExamRoom {
    public:
        set<int> seats;
        int n;
        ExamRoom(int n) {
            this->n = n;
        }
        
        int seat() {
            if(seats.empty()){
                seats.insert(0);
                return 0;
            }
    
            int md = 0;
            int pos = 0;
            int pre = -1;
            if(!seats.empty()){
                int f = *seats.begin();
                if(f > 0){
                    md = f;
                    pos = 0;
                }
            }
    
            for(auto it = seats.begin(); it != seats.end(); it++){
                if(pre == -1){
                    pre = *it;
                    continue;
                }
    
                int cur = *it;
                int dist = (cur - pre) / 2;
                if(dist > md){
                    md = dist;
                    pos = pre + dist;
                }
                pre = cur;
            }
    
            if(!seats.empty()){
                int l = *seats.rbegin();
                if(l < n -1){
                    int dist = (n -1) - l;
                    if(dist > md){
                        md = dist;
                        pos = n - 1;
                    }
                }
            }
            seats.insert(pos);
            return pos;
        }
        
        void leave(int p) {
            seats.erase(p);
        }
    };
    
    /**
     * Your ExamRoom object will be instantiated and called as such:
     * ExamRoom* obj = new ExamRoom(n);
     * int param_1 = obj->seat();
     * obj->leave(p);
     */