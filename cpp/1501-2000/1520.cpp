class Solution {
    public:
        vector<string> maxNumOfSubstrings(string s) {
            int n = s.length();
            vector<int> first(26, n), last(26, -1);
            for(int i = 0; i < n; i++){
                int idx = s[i] - 'a';
                first[idx] = min(first[idx], i);
                last[idx] = max(last[idx], i);
            }
    
            vector<pair<int, int>> intervals;
            for(int i = 0; i < 26; i++){
                if(first[i] == n) continue;
                int left = first[i];
                int right = last[i];
                bool valid = true;
                for(int j = left; j <= right; j++){
                    int idx = s[j] - 'a';
                    if(first[idx] < left){
                        valid = false;
                        break;
                    }
                    right = max(right, last[idx]);
                }
                if(valid && left == first[i]){
                    intervals.push_back({left, right});
                }
            }
    
            sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                return a.second < b.second;
            });
    
            vector<string> res;
            int prev_end = -1;
            for(auto& interval : intervals){
                int start = interval.first;
                int end = interval.second;
                if(start > prev_end){
                    res.push_back(s.substr(start, end - start + 1));
                    prev_end = end;
                }
            }
            return res;
        }
    };