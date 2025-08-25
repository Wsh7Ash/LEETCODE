class Solution {
    public:
        int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
            int n = books.size();
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
    
            for(int i = 0; i < n; i++){
                int w = 0;
                int h = 0;
                for(int j = i; j >= 0; j--){
                    w += books[j][0];
                    if(w > shelfWidth){
                        break;
                    }
                    h = max(h, books[j][1]);
                    dp[i+1] = min(dp[i+1], dp[j] + h);
                }
            }
            return dp[n];
        }
    };