const int MOD = 1e9 + 7;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> events;
        set<int> y_set;

        for(auto& rect : rectangles){
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            events.push_back({x1,1,y1,y2});
            events.push_back({x2,-1,y1,y2});
            y_set.insert(y1);
            y_set.insert(y2);
        }
        sort(events.begin(), events.end());

        vector<int> ys(y_set.begin(), y_set.end());
        map<int, int> y_to_idx;
        for(int i = 0; i < ys.size(); i++){
            y_to_idx[ys[i]] = i;
        }
        vector<int> count(ys.size(), 0);
        long long res = 0;
        int prev_x = events[0][0];

        for(auto& event : events){
            int x = event[0], delta = event[1], y1 = event[2], y2 = event[3];
            res += calculate_area(prev_x, x, ys, count);

            for(int i = y_to_idx[y1]; i < y_to_idx[y2]; i++){
                count[i] += delta;
            }
            prev_x = x;
        }
        return res % MOD;
    }

    long long calculate_area(int x1, int x2, vector<int>& ys, vector<int>& count){
        if(x1 == x2) return 0;
        long long w = x2 - x1;
        long long h = 0;

        for(int i = 0; i <  ys.size() - 1; i++){
            if(count[i] > 0){
                h += ys[i+1] - ys[i];
            }
        }
        return w*h;
    }
};