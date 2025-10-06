class Solution {
    public:
        int maxValueAfterReverse(vector<int>& nums) {
            int n = nums.size();
    
            int originalValue = 0;
    
            for(int i = 0; i <n - 1; i++){
                originalValue += abs(nums[i] - nums[i+1]);
            }
    
            int maxValue = originalValue;
            int maxGain = 0;
    
            for(int j = 1; j < n- 1; j++){
                int gain = abs(nums[0] - nums[j + 1]) - abs(nums[j] - nums[j+1]);
                maxGain = max(maxGain, gain);
            }
    
            for(int i = 1; i < n - 1; i++){
                int gain = abs(nums[i - 1] - nums[n - 1]) - abs(nums[i - 1] - nums[i]);
                maxGain = max(maxGain, gain);
            }
    
            int maxPairSum = INT_MIN;
            int minPairSum = INT_MAX;
    
            for(int i = 0; i < n - 1; i++){
                int a = nums[i];
                int b = nums[i + 1];
    
                maxPairSum = max(maxPairSum, min(a,b));
                minPairSum = min(minPairSum, max(a,b));
            }
    
            maxGain = max(maxGain, max(0, (maxPairSum - minPairSum) * 2));
    
            return originalValue + maxGain;
        }
    };