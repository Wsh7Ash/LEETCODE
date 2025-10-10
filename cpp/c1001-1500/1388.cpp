class Solution {
    public:
        int maxSizeSlices(vector<int>& slices) {
            int n = slices.size();
            int k = n / 3;
    
            vector<vector<int>> dp1(n, vector<int>(k + 1, 0));
    
            dp1[1][1] = slices[1];
    
            for(int i = 2; i < n; i++){
                for(int j = 1; j <= k; j++){
                    dp1[i][j] = max(dp1[i-1][j], dp1[i-2][j-1] + slices[i]);
                }
            }
    
            vector<vector<int>> dp2(n, vector<int>(k + 1, 0));
    
            dp2[1][1] = slices[0];
            for(int i = 2; i < n; i++){
                for(int j = 1; j <= k; j++){
                    dp2[i][j] = max(dp2[i-1][j], dp2[i-2][j-1] + slices[i-1]);
                }
            }
    
            return max(dp1[n-1][k], dp2[n-1][k]);
        }
    };