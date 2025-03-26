#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // Create prefix sum array
        vector<long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        
        return mergeSortCount(prefixSums, 0, n + 1, lower, upper);
    }
    
private:
    int mergeSortCount(vector<long>& sums, int left, int right, int lower, int upper) {
        // Base case: if range is 1 or less, no valid subarrays
        if (right - left <= 1) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortCount(sums, left, mid, lower, upper) + 
                   mergeSortCount(sums, mid, right, lower, upper);
        
        // Count valid ranges across the two halves
        int j = mid, k = mid, t = mid;
        vector<long> temp(right - left);
        int r = 0;
        
        // For each left half element, find valid ranges in right half
        for (int i = left; i < mid; i++) {
            // Find lower bound
            while (j < right && sums[j] - sums[i] < lower) j++;
            // Find upper bound
            while (k < right && sums[k] - sums[i] <= upper) k++;
            count += (k - j);
        }
        
        // Merge step
        int i = left;
        while (i < mid || t < right) {
            if (i >= mid) temp[r++] = sums[t++];
            else if (t >= right) temp[r++] = sums[i++];
            else if (sums[i] <= sums[t]) temp[r++] = sums[i++];
            else temp[r++] = sums[t++];
        }
        
        // Copy back to original array
        for (int x = 0; x < r; x++) {
            sums[left + x] = temp[x];
        }
        
        return count;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {-2, 5, -1};
    cout << solution.countRangeSum(nums1, -2, 2) << endl;  // Output: 3
    
    // Test case 2
    vector<int> nums2 = {0};
    cout << solution.countRangeSum(nums2, 0, 0) << endl;   // Output: 1
    
    return 0;
}
This solution uses a divide-and-conquer approach with merge sort. Here's how it works:

Prefix Sums:
First, we create a prefix sum array where sums[i] represents sum from index 0 to i-1
For range [i,j], the sum = sums[j+1] - sums[i]
We use long to prevent integer overflow
Merge Sort Approach:
Divide the array into two halves recursively
For each division:
Count valid ranges within left half
Count valid ranges within right half
Count valid ranges across halves
Merge the sorted halves
Counting Across Halves:
For each element in left half
Find how many elements in right half form a valid range sum
Use two pointers (j for lower bound, k for upper bound)
Number of valid ranges = k - j
Time Complexity: O(n log n)

Merge sort takes O(n log n)
At each level, we spend O(n) time counting ranges
There are O(log n) levels
Space Complexity: O(n) for the prefix sum array and temporary merge array

For Example 1: nums = [-2,5,-1], lower = -2, upper = 2

Prefix sums: [0,-2,3,2]
Valid ranges:
[0,0]: sums[1]-sums[0] = -2
[2,2]: sums[3]-sums[2] = -1
[0,2]: sums[3]-sums[0] = 2
Output: 3
The solution handles all constraints:

Works for array length 1 to 10^5
Handles integers from -2^31 to 2^31-1
Works for lower/upper bounds from -10^5 to 10^5
Result fits in 32-bit integer