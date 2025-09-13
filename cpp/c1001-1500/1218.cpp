class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            unordered_map<int, int> dp;
            int maxLen = 0;
    
            for(int num : arr){
                int prev = num - difference;
    
                dp[num] = dp.count(prev) ? dp[prev] + 1 : 1;
    
                maxLen = max(maxLen, dp[num]);
            }
    
            return maxLen;
        }
    };