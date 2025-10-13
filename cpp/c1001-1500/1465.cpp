class Solution {
    public:
        int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
            const int MOD =  1e9+7;
    
            horizontalCuts.push_back(0);
            horizontalCuts.push_back(h);
            verticalCuts.push_back(0);
            verticalCuts.push_back(w);
    
            sort(horizontalCuts.begin(), horizontalCuts.end());
            sort(verticalCuts.begin(), verticalCuts.end());
    
            long long maxH = 0, maxV = 0;
    
            for(int i = 1; i < horizontalCuts.size(); i++){
                maxH = max(maxH, (long long)horizontalCuts[i] - horizontalCuts[i-1]);
            }
            for(int i = 1; i < verticalCuts.size(); i++){
                maxV = max(maxV, (long long)verticalCuts[i] - verticalCuts[i-1]);
            }
    
            return(maxH * maxV) % MOD;
        }
    };