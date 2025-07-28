class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            unordered_map<int, int> rc;
            rc[0] = 1;
            int ps = 0;
            int res = 0;
    
            for(int num : nums){
                ps += num;
                int r = ps % k;
                if(r < 0) r += k;
                if(rc.find(r) != rc.end()) res += rc[r];
                rc[r]++;
            }
            return res;
        }
    };