class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<int> tc(n + 1, 0);
            vector<bool> ts(n + 1, false);
            
            for(const auto& t : trust){
                ts[t[0]] = true;
                tc[t[1]]++;
    
            }
            for(int i = 1; i <= n; i++){
                if(!ts[i] && tc[i] == n - 1) return i;
            }
    
            return -1;
    
        }
    };