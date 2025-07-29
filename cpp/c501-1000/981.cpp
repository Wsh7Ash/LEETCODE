class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        const vector<pair<int, string>>& entries = store[key];
        int left = 0;
        int right = entries.size() - 1;
        string res = "";
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(entries[mid].first <= timestamp){
                res = entries[mid].second;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<pair<int, string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */