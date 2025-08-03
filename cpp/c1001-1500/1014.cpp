class Solution {
    public:
        int maxScoreSightseeingPair(vector<int>& values) {
            int ms = 0;
            int mp = values[0] + 0;
    
            for(int j = 1; j < values.size(); j++){
                int cs = mp + values[j] - j;
                ms = max(ms, cs);
                mp = max(mp, values[j] + j);
            }
            return ms;
        }
    };