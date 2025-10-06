class Solution {
    public:
        int maxJumps(vector<int>& arr, int d) {
            int n = arr.size();
            vector<pair<int, int>> heights;
    
            for(int i = 0; i < n; i++){
                heights.push_back({arr[i], i});
            }
    
            sort(heights.begin(), heights.end());
    
            vector<int> dp(n, 1);
            int res = 1;
    
            for(auto& [h, i] : heights){
                for(int j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; j++){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
    
                for(int j = i - 1; j >= max(i - d, 0) && arr[j] < arr[i]; j--){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
    
                res = max(res, dp[i]);
            }
    
            return res;
        }
    };