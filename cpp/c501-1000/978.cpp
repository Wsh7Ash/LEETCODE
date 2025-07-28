#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int max_len = 1;
        int cur_len = 1;
        int prev_diff = arr[1] - arr[0];

        if (prev_diff != 0) {
            cur_len = 2;
            max_len = 2;
        }

        for (int i = 2; i < n; ++i) {
            int cur_diff = arr[i] - arr[i - 1];
            if ((prev_diff > 0 && cur_diff < 0) || (prev_diff < 0 && cur_diff > 0)) {
                cur_len += 1;
                max_len = max(max_len, cur_len);
            } else {
                if (cur_diff != 0) {
                    cur_len = 2;
                    max_len = max(max_len, cur_len);
                } else {
                    cur_len = 1;
                }
            }
            prev_diff = cur_diff;
        }

        return max_len;
    }
};