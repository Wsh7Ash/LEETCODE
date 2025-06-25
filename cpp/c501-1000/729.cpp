class MyCalendar {
    public:
        vector<pair<int, int>> es;
        MyCalendar() {
            
        }
        
        bool book(int startTime, int endTime) {
            for(const auto& e : es){
                if(startTime < e.second && endTime > e.first){
                    return false;
                }
            }
            es.emplace_back(startTime, endTime);
            return true;
        }
    };
    
    /**
     * Your MyCalendar object will be instantiated and called as such:
     * MyCalendar* obj = new MyCalendar();
     * bool param_1 = obj->book(startTime,endTime);
     */