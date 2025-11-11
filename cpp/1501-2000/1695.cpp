class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> uniqueElements;
            int left = 0, right = 0;
            int curSum = 0, maxSum = 0;
    
            while(right < n){
                while(uniqueElements.find(nums[right]) != uniqueElements.end()){
                    uniqueElements.erase(nums[left]);
                    curSum -= nums[left];
                    left++;
                }
                uniqueElements.insert(nums[right]);
                curSum += nums[right];
                maxSum = max(curSum, maxSum);
                right++;
            }
            return maxSum;
        }
    };