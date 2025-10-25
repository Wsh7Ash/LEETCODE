class Solution {
    public:
        int countSubstrings(string s, string t) {
            int m = s.length();
            int n = t.length();
            int res = 0;
            vector<vector<int>> same(m+1, vector<int>(n+1, 0));
            vector<vector<int>> diff(m+1, vector<int>(n+1, 0));
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    if(s[i-1] == t[j-1]){
                        same[i][j] = same[i-1][j-1] + 1;
                        diff[i][j] = diff[i-1][j-1];
                    }else{
                        same[i][j] = 0;
                        diff[i][j] = same[i-1][j-1] + 1;
                    }
                    res += diff[i][j];
                }
            }
            return res;
        }
    };