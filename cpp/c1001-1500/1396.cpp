class UndergroundSystem {
    private:
        struct PairHash{
            template <class T1, class T2>
            size_t operator() (const pair<T1, T2>& p) const{
                auto hash1 = hash<T1>{}(p.first);
                auto hash2 = hash<T2>{}(p.second);
                return hash1 ^ (hash2 << 1);
            }
        };
    
        unordered_map<int, pair<string, int>> checkIns;
        unordered_map<pair<string, string>, pair<long long, int>, PairHash> travelStats;
    
    
    public:
        UndergroundSystem() {
            
        }
        
        void checkIn(int id, string stationName, int t) {
            checkIns[id] = {stationName, t};    
        }
        
        void checkOut(int id, string stationName, int t) {
            auto& checkIn = checkIns[id];
            string startStation = checkIn.first;
            int travelTime = t - checkIn.second;
    
            pair<string, string> route = {startStation, stationName};
            travelStats[route].first += travelTime;
            travelStats[route].second++;
    
            checkIns.erase(id);
        }
        
        double getAverageTime(string startStation, string endStation) {
            pair<string, string> route = {startStation, endStation};
            auto& stats = travelStats[route];
            return (double)stats.first / stats.second;
        }
    };
    
    /**
     * Your UndergroundSystem object will be instantiated and called as such:
     * UndergroundSystem* obj = new UndergroundSystem();
     * obj->checkIn(id,stationName,t);
     * obj->checkOut(id,stationName,t);
     * double param_3 = obj->getAverageTime(startStation,endStation);
     */