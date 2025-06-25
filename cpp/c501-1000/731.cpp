class MyCalendarTwo {
    public:
        vector<pair<int, int>> es;
        vector<pair<int, int>> ol;
        MyCalendarTwo() {
            
        }
        
        bool book(int startTime, int endTime) {
            for(const auto& i : ol){
                if(startTime < i.second && endTime > i.first){
                    return false;
                }
            }
            for(const auto& e : es){
                int ols = max(startTime, e.first);
                int ole = min(endTime, e.second);
                if(ols < ole){
                    ol.emplace_back(ols, ole);
                }
            }
            es.emplace_back(startTime, endTime);
            return true;
        }
    };
    
    /**
     * Your MyCalendarTwo object will be instantiated and called as such:
     * MyCalendarTwo* obj = new MyCalendarTwo();
     * bool param_1 = obj->book(startTime,endTime);
     */