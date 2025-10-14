class Solution {
    public:
        vector<int> avoidFlood(vector<int>& rains) {
            int n = rains.size();
            vector<int> res(n, -1);
            unordered_map<int, int> lastRain;
            set<int> dryDays;
    
            for(int i = 0; i < n; i++){
                if(rains[i] == 0){
                    dryDays.insert(i);
                    res[i] = 1;
                }else{
                    int lake = rains[i];
                    if(lastRain.count(lake)){
                        int lastDay = lastRain[lake];
                        auto it = dryDays.upper_bound(lastDay);
                        if(it == dryDays.end() || *it >= i){
                            return {};
                        }
                        int dryDay = *it;
                        res[dryDay] = lake;
                        dryDays.erase(dryDay);
                    }
                    lastRain[lake] = i;
                }
            }
    
            for(int day : dryDays){
                res[day] = 1;
            }
            return res;
        }
    };