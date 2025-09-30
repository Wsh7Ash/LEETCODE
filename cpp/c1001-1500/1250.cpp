class Solution {
    public:
        bool isGoodArray(vector<int>& nums) {
           int res = nums[0];
           for(int i = 1; i < nums.size(); i++){
            res = gcd(res, nums[i]);
    
            if(res == 1) return true;
           } 
           return res == 1;
        }
    private:
        int gcd(int x, int y){
            while(y != 0){
                int t = y;
                y = x % y;
                x = t;
            }
            return x;
        }
    };