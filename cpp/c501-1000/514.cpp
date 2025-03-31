class Solution {
    public:
        int findRotateSteps(string ring, string key) {
            unordered_map<char, vector<int>> charPos;
            int n = ring.size();
            int m = key.size();
    
            for(int i = 0; i < n; i++){
                charPos[ring[i]].push_back(i);
            }
    
            vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    
            for(int pos : charPos[key[0]]){
                int steps = min(pos, n - pos);
                dp[0][pos] = steps;
            }
    
            for(int i = 1; i < m; i++){
                for(int curPos : charPos[key[i]]){
                    for(int prevPos : charPos[key[i-1]]){
                        int diff = abs(curPos - prevPos);
                        int steps = min(diff, n - diff);
                        if(dp[i-1][prevPos] != INT_MAX){
                            dp[i][curPos] = min(dp[i][curPos], dp[i-1][prevPos] + steps);
                        }
                    }
                }
            }
            int minSteps = *min_element(dp[m-1].begin(), dp[m-1].end());
            return minSteps + m;
        }
    };