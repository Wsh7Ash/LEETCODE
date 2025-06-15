class Solution {
    public:
        int countBinarySubstrings(string s) {
            vector<int> g;
            int c = 1;
            for(int i = 1; i < s.size(); i++){
                if(s[i] == s[i-1]){
                    c++;
                }else{
                    g.push_back(c);
                    c = 1;
                }
            }
            g.push_back(c);
            int res = 0;
            for(int i = 1; i < g.size(); i++){
                res += min(g[i-1], g[i]);
            }
            return res;
        }
    };