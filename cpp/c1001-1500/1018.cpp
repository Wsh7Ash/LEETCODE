class Solution {
    public:
        vector<bool> prefixesDivBy5(vector<int>& nums) {
            vector<bool> res;
            int cur = 0;
            for(int num : nums){
                cur = (cur  * 2 + num) % 5;
                res.push_back(cur == 0);
            }
            return res;
        }
    };