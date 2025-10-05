class Solution {
    public:
        pair<int, int> getCoord(char c) {
            int idx = c - 'A';
            return {idx / 6, idx % 6};
        }
    
        int dist(char a, char b) {
            if (a == 0 || b == 0) return 0; 
            auto coordA = getCoord(a);
            auto coordB = getCoord(b);
            return abs(coordA.first - coordB.first) + abs(coordA.second - coordB.second);
        }
        
        int minimumDistance(string word) {
            int n = word.length();
            if (n <= 2) return 0;
    
            vector<vector<int>> dp(n, vector<int>(n + 1, INT_MAX / 2));
    
            dp[0][n] = 0;
    
            for (int i = 1; i < n; i++) {
                char current = word[i];
                
                for (int j = 0; j <= n; j++) {
                    if (dp[i-1][j] == INT_MAX / 2) continue;
                    
                    char prev = word[i-1];
                    int cost = dist(prev, current);
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + cost);
                }
                
                for (int j = 0; j <= n; j++) {
                    if (dp[i-1][j] == INT_MAX / 2) continue;
                    
                    char otherFingerChar;
                    if (j == n) {
                        otherFingerChar = 0;
                    } else {
                        otherFingerChar = word[j];
                    }
                    
                    int cost = dist(otherFingerChar, current);
                    dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + cost);
                }
            }
    
            int res = INT_MAX;
            for (int j = 0; j <= n; j++) {
                res = min(res, dp[n-1][j]);
            }
            return res;
        }
    };