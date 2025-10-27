class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int res = 0;
        int cur = 0;
        for(const auto& task : tasks){
            int actual = task[0];
            int min = task[1];
            if(cur < min){
                res += (min - cur);
                cur = min;
            }
            cur -= actual;
        }
        return res;
    }
};