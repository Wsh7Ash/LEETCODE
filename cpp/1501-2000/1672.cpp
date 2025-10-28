class Solution {
    public:
        int maximumWealth(vector<vector<int>>& accounts) {
            int mw = 0;
            for(const auto& c : accounts){
                mw = max(mw, accumulate(c.begin(), c.end(), 0));
            }
            return mw;
        }
    };