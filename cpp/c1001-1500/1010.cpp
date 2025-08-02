class Solution {
    public:
        int numPairsDivisibleBy60(vector<int>& time) {
            unordered_map<int, int> rc;
            for(int t : time){
                int r = t % 60;
                rc[r]++;
            }
    
            int pairs = 0;
            for(auto& [r, c] : rc){
                if(r == 0 || r == 30){
                    pairs += (long long)c * (c - 1) / 2;
                }else if(r < 30 && rc.find(60 - r) != rc.end()){
                    pairs += c * rc[60 - r];
                }
            }
            return pairs;
        }
    };