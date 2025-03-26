class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() <= 2) return nums.size(); // No need to process if the array has 2 or fewer elements
            
            int k = 2; // We are allowed to have at most 2 duplicates
            for (int i = 2; i < nums.size(); ++i) {
                // If the current number is not a duplicate (more than 2 occurrences), move it to the correct position
                if (nums[i] != nums[k - 2]) {
                    nums[k] = nums[i];
                    ++k; // Increment the position where we want to place the next valid element
                }
            }
            
            return k; // Return the new length of the array
        }
    };
    