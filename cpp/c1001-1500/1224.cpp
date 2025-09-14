class Solution {
    public:
        int maxEqualFreq(vector<int>& nums) {
            unordered_map<int, int> freq, count;
            int mf = 0;
            int res = 0;
            for (int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                count[freq[num]]--;
                freq[num]++;
                count[freq[num]]++;
                mf = max(mf, freq[num]);
                
                bool valid = false;
                if (mf == 1) {
                    valid = true;
                } else if (mf * count[mf] == i) {
                    valid = true;
                } else if ((mf - 1) * (count[mf - 1]) + mf == i + 1) {
                    valid = true;
                }
                if (valid) {
                    res = i + 1;
                }
            }
            return res;
        }
    };