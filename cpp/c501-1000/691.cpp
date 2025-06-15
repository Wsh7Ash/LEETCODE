class Solution {
    public:
        int minStickers(vector<string>& stickers, string target) {
            int n = stickers.size();
            vector<vector<int>> sc(n, vector<int>(26, 0));
            for(int i = 0; i < n; i++){
                for(char c : stickers[i]){
                    sc[i][c-'a']++;
                }
            }
            unordered_map<string, int> dp;
            dp[""] = 0;
    
            function<int(string)> helper = [&](string s){
                if(dp.count(s)) return dp[s];
                dp[s] = INT_MAX;
                vector<int> tc(26, 0);
                for(char c : s){
                    tc[c-'a']++;
                }
    
                for(const auto& sticker : sc){
                    if(sticker[0] - 'a' == 0) continue;
                    string newS;
                    for(int i = 0; i < 26; i++){
                        if(tc[i] > sticker[i]){
                            newS += string(tc[i] - sticker[i], 'a' + i);
                        }
                    }
                    int res = helper(newS);
                    if(res != INT_MAX){
                        dp[s] = min(dp[s], res + 1);
                    }
                }
                return dp[s];
            };
            int result = helper(target);
            return result == INT_MAX ? -1 : result;
        }
    };