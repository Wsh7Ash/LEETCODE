class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string s) {
            vector<vector<int>> res;
            int n = s.size();
            if(n == 0) return res;
    
            int start = 0;
            for(int end = 1; end < n; end++){
                if(s[end] != s[start]){
                    if(end - start >= 3){
                        res.push_back({start, end - 1});
                    }
                    start = end;
                }
            }
            if(n - start >= 3) res.push_back({start, n - 1});
            return res;
        }
    };