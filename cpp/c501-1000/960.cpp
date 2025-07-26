class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int m = strs.size();
            if(m == 0) return 0;
            int n = strs[0].size();
            vector<int> dp(n, 1);
            int max_len = 1;
    
            for(int i =1; i <n; i++){
                for(int j = 0; j < i; j++){
                    bool valid = true;
                    for(const string& s : strs){
                        if(s[j] > s[i]){
                            valid = false;
                            break;
                        }
                    }
                    if(valid) dp[i] = max(dp[i], dp[j] + 1);
                }
                max_len = max(max_len, dp[i]);
            }
            return n - max_len;
        }
    };