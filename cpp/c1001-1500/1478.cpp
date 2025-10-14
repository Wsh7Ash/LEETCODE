class Solution {
    public:
        int minDistance(vector<int>& houses, int k) {
            int n = houses.size();
            sort(houses.begin(), houses.end());
    
            vector<vector<int>> cost(n, vector<int>(n, 0));
    
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    int median = houses[(i + j) / 2];
                    for(int m = i; m <= j; m++){
                        cost[i][j] += abs(houses[m] - median);
                    }
                }
            }
    
            vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX / 2));
    
            for(int i = 0; i < n; i++){
                dp[i][1] = cost[0][i];
            }
    
            for(int mailboxes = 2; mailboxes <= k; mailboxes++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < i; j++){
                        dp[i][mailboxes] = min(dp[i][mailboxes], dp[j][mailboxes - 1] + cost[j + 1][i]);
                    }
                }
            }
            return dp[n - 1][k];
        }
    };