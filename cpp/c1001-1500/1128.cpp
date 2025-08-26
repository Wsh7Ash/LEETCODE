class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> count;
            for(auto& domino : dominoes){
                int a = domino[0];
                int b = domino[1];
                pair<int, int> key = {min(a, b), max(a,b)};
                count[key]++;
            }
    
            int res = 0;
            for(auto& it :  count){
                int n = it.second;
                res += n * (n - 1)/ 2;
            }
            return res;
        }
    };