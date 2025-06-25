class MyCalendarThree {
    public:
        map<int, int> tl;
        MyCalendarThree() {
            
        }
        
        int book(int startTime, int endTime) {
            tl[startTime]++;
            tl[endTime]--;
            int maxK = 0;
            int cur = 0;
            for(const auto& e : tl){
                cur += e.second;
                if(cur > maxK){
                    maxK = cur;
                }
            }
            return maxK;
        }
    };
    
    /**
     * Your MyCalendarThree object will be instantiated and called as such:
     * MyCalendarThree* obj = new MyCalendarThree();
     * int param_1 = obj->book(startTime,endTime);
     */