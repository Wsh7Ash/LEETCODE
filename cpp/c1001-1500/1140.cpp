class Solution {
    public:
        int n;
        vector<int> suffixSum;
        vector<vector<int>> dp;
    
        int solve(int i, int m, vector<int>& piles){
            if(i >= n) return 0;
            if(dp[i][m] != -1) return dp[i][m];
    
            int res = 0;
            for(int x = 1; x <= 2 * m; x++){
                if(i + x > n) break;
                int taken = suffixSum[i] - suffixSum[i+x];
                int new_m = max(m, x);
                int next = solve(i+x, new_m, piles);
                res = max(res, taken + (suffixSum[i+x] - next));
            }
            return dp[i][m] = res;
        }
        int stoneGameII(vector<int>& piles) {
            n = piles.size();
            suffixSum.resize(n+1, 0);
            for(int i = n-1; i>= 0; i--){
                suffixSum[i] = piles[i] + suffixSum[i+1];
            }
            dp.resize(n, vector<int>(201, -1));
            return solve(0, 1, piles);
        }
    };