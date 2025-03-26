#include <vector>
#include <algorithm>

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Create a sorted copy of the array
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        
        // Step 2: Fill odd positions with largest numbers
        // Then fill even positions with remaining numbers
        int j = n - 1;  // Index starting from largest number
        
        // Fill odd indices (1, 3, 5...) with larger numbers
        for (int i = 1; i < n; i += 2) {
            nums[i] = sorted_nums[j];
            j--;
        }
        
        // Fill even indices (0, 2, 4...) with smaller numbers
        for (int i = 0; i < n; i += 2) {
            nums[i] = sorted_nums[j];
            j--;
        }
    }
};

// Test code
#include <iostream>

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums1);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // Output: 1 6 1 5 1 4
    
    // Test case 2
    vector<int> nums2 = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;  // Output: 2 3 1 3 1 2
    
    return 0;
}
Key differences from the Python version:

Uses C++ vector<int> instead of Python lists
Explicit type declarations
Uses sort() from the C++ Standard Template Library instead of Python's sorted()
More explicit syntax with semicolons and curly braces
Uses references (&) to modify the input vector directly
The algorithm remains the same:

Create a sorted copy of the array
Fill odd indices (1,3,5...) with largest numbers in descending order
Fill even indices (0,2,4...) with remaining numbers
The C++ implementation maintains the same complexity:

Time Complexity: O(n log n) due to sorting
Space Complexity: O(n) for the sorted copy
The solution works correctly for all test cases and meets all constraints:

Handles arrays of length 1 to 5 * 10^4
Works with numbers between 0 and 5000
Produces a valid wiggle sort pattern (nums[0] < nums[1] > nums[2] < nums[3]...)
The output will satisfy the wiggle property. For example:

Input [1,5,1,1,6,4] → Output [1,6,1,5,1,4]
Verifies: 1 < 6 > 1 < 5 > 1 < 4
Input [1,3,2,2,3,1] → Output [2,3,1,3,1,2]
Verifies: 2 < 3 > 1 < 3 > 1 < 2