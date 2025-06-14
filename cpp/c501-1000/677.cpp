class MapSum {
    public:
        unordered_map<string, int> map;
        MapSum() {
            
        }
        
        void insert(string key, int val) {
            map[key] = val;
        }
        
        int sum(string prefix) {
            int total = 0;
            for(auto& pair : map){
                const string& key = pair.first;
                if(key.substr(0, prefix.length()) == prefix){
                    total += pair.second;
                }
            }
            return total;
        }
    };
    
    /**
     * Your MapSum object will be instantiated and called as such:
     * MapSum* obj = new MapSum();
     * obj->insert(key,val);
     * int param_2 = obj->sum(prefix);
     */