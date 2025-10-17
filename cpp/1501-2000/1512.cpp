class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            unordered_map<int, int> freq;
            int res = 0;
    
            for(int num : nums){
                res += freq[num];
                freq[num]++;
            }
            return res;
        }
    };