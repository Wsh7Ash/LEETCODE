class Solution {
    public:
        int minTaps(int n, vector<int>& ranges) {
            
            vector<int> maxReach(n + 1, 0);
    
            for(int i = 0; i <= n; i++){
                int left = max(0, i - ranges[i]);
                int right = min(n, i + ranges[i]);
                maxReach[left] = max(maxReach[left], right - left);
            }
    
            int taps = 0;
            int curEnd = 0;
            int farthest = 0;
    
            for(int i = 0; i < n; i++){
                farthest = max(farthest, i + maxReach[i]);
    
                if(i == curEnd){
                    taps++;
                    curEnd = farthest;
    
                    if(curEnd <= i) return -1;
                }
            }
    
            return taps;
        }
    };