class Solution {
    public:
        int maxValue(vector<vector<int>>& events, int k) {
            int n = events.size();
            sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            });
    
            vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
            for(int i = 1; i <= n; i++){
                int start = events[i - 1][0];
                int end = events[i - 1][1];
                int value = events[i - 1][2];
    
                int prevNonOverlap = findPrevNonOverlap(events, i - 1);
                for(int j = 1; j <= k; j++){
                    dp[i][j] = dp[i-1][j];
                    if(prevNonOverlap == -1){
                        dp[i][j] = max(dp[i][j], value);
                    }else{
                        dp[i][j] = max(dp[i][j], dp[prevNonOverlap + 1][j-1] + value);
                    }
                }
            }
            return dp[n][k];
        }
    
        int findPrevNonOverlap(vector<vector<int>>& events, int curIndex){
            int target = events[curIndex][0];
            int left = 0, right = curIndex - 1;
            int res = -1;
    
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(events[mid][1] < target){
                    res = mid;
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
            return res;
        }
    };