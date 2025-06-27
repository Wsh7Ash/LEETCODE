class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
            });
            int res = 0;
            int l = -1;
            int r = -1;
    
            for(const auto& interval : intervals){
                int s = interval[0];
                int e = interval[1];
                if(s > r){
                    res += 2;
                    r = e;
                    l = e - 1;
                }else if( s > l){
                    res += 1;
                    l = r;
                    r = e;
                }
            }
            return res;
        }
    };