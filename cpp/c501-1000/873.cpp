class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, int> index;
            for(int i = 0; i < n; i++){
                index[arr[i]] = i;
            }
    
            vector<vector<int>> dp(n, vector<int>(n, 2));
            int maxlen = 0;
    
            for(int j = 1; j < n; j++){
                for(int i = 0; i < j; i++){
                    int target = arr[j] - arr[i];
                    if(index.find(target) != index.end() && index[target] < i){
                        int k = index[target];
                        dp[i][j] = dp[k][i] + 1;
                        if(dp[i][j] > maxlen){
                            maxlen = dp[i][j];
                        }
                    }
                }
            }
            return maxlen >= 3 ? maxlen : 0;
        }
    };