class Solution {
    public:
        bool xorGame(vector<int>& nums) {
            int txor = 0;
            for(int n : nums){
                txor ^= n;
            }
            if(txor == 0) return true;
            return nums.size() % 2 == 0;
        }
    };