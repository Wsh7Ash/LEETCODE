class Solution {
    private:
        // Partition function for QuickSelect
        int partition(vector<int>& nums, int left, int right) {
            // Choose rightmost element as pivot
            int pivot = nums[right];
            int i = left - 1;
            
            // Move elements smaller than pivot to the left
            for (int j = left; j < right; j++) {
                if (nums[j] <= pivot) {
                    i++;
                    swap(nums[i], nums[j]);
                }
            }
            
            // Place pivot in its final position
            swap(nums[i + 1], nums[right]);
            return i + 1;
        }
        
        // QuickSelect to find kth largest
        int quickSelect(vector<int>& nums, int left, int right, int k) {
            if (left <= right) {
                int pivotIndex = partition(nums, left, right);
                
                // If pivot is at k-1, we found our element
                if (pivotIndex == k - 1) {
                    return nums[pivotIndex];
                }
                // If pivot is after k-1, search left side
                else if (pivotIndex > k - 1) {
                    return quickSelect(nums, left, pivotIndex - 1, k);
                }
                // If pivot is before k-1, search right side
                else {
                    return quickSelect(nums, pivotIndex + 1, right, k);
                }
            }
            return -1; // Should never reach here given constraints
        }
        
    public:
        int findKthLargest(vector<int>& nums, int k) {
            return quickSelect(nums, 0, nums.size() - 1, nums.size() - k + 1);
        }
    };