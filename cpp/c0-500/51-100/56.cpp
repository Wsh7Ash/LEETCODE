class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        for(const auto& interval : intervals){
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};