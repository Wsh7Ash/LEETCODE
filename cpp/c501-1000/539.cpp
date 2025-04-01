class Solution {
    public:
        int findMinDifference(vector<string>& timePoints) {
            vector<int> m1;
            for(string& time : timePoints){
                int h = stoi(time.substr(0,2));
                int m = stoi(time.substr(3,2));
                m1.push_back(h*60 + m);
            }
            sort(m1.begin(), m1.end());
            int minDiff = INT_MAX;
            for(int i = 1; i < m1.size(); i++){
                minDiff = min(minDiff, m1[i] - m1[i-1]);
            }
            minDiff = min(minDiff, (m1[0] + 1440) - m1.back());
            return minDiff;
        }
    };