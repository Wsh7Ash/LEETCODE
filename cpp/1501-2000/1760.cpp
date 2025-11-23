class Solution {
    public:
        int minimumSize(vector<int>& nums, int maxOperations) {
            int left = 1;
            int right = 1e9;
            int res = right;
    
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(canAchieve(nums, maxOperations, mid)){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return res;
        }
    
        bool canAchieve(vector<int>& nums, int maxOps, int penalty){
            long long operations = 0;
            for(int num : nums){
                if(num > penalty){
                    operations += (num - 1) / penalty;
                }
            }
            return operations <= maxOps;
        }
    };