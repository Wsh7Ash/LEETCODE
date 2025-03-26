class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                // If the target is found, return true
                if (nums[mid] == target) return true;
    
                // Handle duplicate elements by shrinking the search space
                if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                    ++left;
                    --right;
                }
                // Left half is sorted
                else if (nums[left] <= nums[mid]) {
                    if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1; // Search left
                    } else {
                        left = mid + 1; // Search right
                    }
                }
                // Right half is sorted
                else {
                    if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1; // Search right
                    } else {
                        right = mid - 1; // Search left
                    }
                }
            }
    
            return false; // Target not found
        }
    };
    