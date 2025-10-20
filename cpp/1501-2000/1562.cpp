class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(m == n) return n;
        vector<pair<int, int>> segments(n+2, {0,0});
        int count = 0;
        int res = -1;
        for(int step = 0; step < n; step++){
            int pos = arr[step];
            int l = segments[pos - 1].first;
            int r = segments[pos + 1].second;
            int maxlen = l + r + 1;
            segments[pos - l].second = maxlen;
            segments[pos + r].first = maxlen;
            if(l == m) count--;
            if(r == m) count--;
            if(maxlen == m) count++;
            if(count > 0) res = step + 1;
        }
        return res;
    }
};