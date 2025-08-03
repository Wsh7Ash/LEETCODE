class Solution {
    public:
        bool canThreePartsEqualSum(vector<int>& arr) {
            int ts = accumulate(arr.begin(), arr.end(), 0);
            if(ts % 3 != 0) return false;
    
            int target = ts / 3;
            int cs = 0;
            int c = 0;
            for(int num : arr){
                cs += num;
                if(cs == target){
                    c++;
                    cs = 0;
                }
            }
            return c >= 3;
        }
    };