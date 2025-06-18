class Solution {
    public:
        unordered_map<int, int> map;
        int m;
        Solution(int n, vector<int>& blacklist) {
            m = n - blacklist.size();
            unordered_set<int> black;
            for(int num : blacklist){
                if(num >= m){
                    black.insert(num);
                }
            }
            int next = m;
            for(int num : blacklist){
                if(num < m){
                    while(black.count(next)){
                        next++;
                    }
                    map[num] = next;
                    next++;
                }
            }
        }
        
        int pick() {
            int r = rand() % m;
            if(map.count(r)){
                return map[r];
            }        
            return r;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(n, blacklist);
     * int param_1 = obj->pick();
     */