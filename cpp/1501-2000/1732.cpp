class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int curAltitude = 0;
            int maxAltitude = 0;
            for(int i = 0; i < gain.size(); i++){
                curAltitude += gain[i];
                maxAltitude = max(maxAltitude, curAltitude);
            }
            return maxAltitude;
        }
    };