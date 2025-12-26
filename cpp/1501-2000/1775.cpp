class Solution {
    public:
        int minOperations(vector<int>& nums1, vector<int>& nums2) {
            int sum1 = 0, sum2 = 0;
            for(int num : nums1) sum1 += num;
            for(int num : nums2) sum2 += num;
    
            if(sum1 == sum2) return 0;
    
            if(sum1 > sum2){
                swap(nums1, nums2);
                swap(sum1, sum2);
            }
    
            priority_queue<int> gains;
            for(int num : nums1){
                if(num < 6) gains.push(6 - num);
            }
            for(int num : nums2){
                if(num > 1) gains.push(num - 1);
            }
    
            int operations = 0;
            int diff = sum2 - sum1;
            while(!gains.empty()  && diff > 0){
                int gain = gains.top();
                gains.pop();
                diff -= min(gain, diff);
                operations++;
                if(diff <= 0) return operations;
            }
    
            return diff > 0 ? -1 : operations;
        }
    };