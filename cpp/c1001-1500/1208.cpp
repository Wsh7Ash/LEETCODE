class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost) {
            int n = s.length();
            vector<int> cost(n);
            for(int i = 0; i < n; i++){
                cost[i] = abs(s[i] - t[i]);
            }
    
            int l = 0;
            int cc = 0;
            int ml = 0;
    
            for(int r = 0; r < n; r++){
                cc += cost[r];
                while(cc > maxCost){
                    cc -= cost[l];
                    l++;
                }
                ml = max(ml, r-l+1);
            }
            return ml;
        }
    };