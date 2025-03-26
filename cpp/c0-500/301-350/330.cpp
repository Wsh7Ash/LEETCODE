#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;  // Smallest number we can't form yet
        int patches = 0;  // Number of patches needed
        int i = 0;  // Index in nums array
        
        // Continue until we can form all numbers up to n
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // If current number can extend our range
                miss += nums[i];
                i++;
            } else {
                // Need to patch with miss itself
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 3};
    cout << solution.minPatches(nums1, 6) << endl;  // Output: 1
    
    // Test case 2
    vector<int> nums2 = {1, 5, 10};
    cout << solution.minPatches(nums2, 20) << endl;  // Output: 2
    
    // Test case 3
    vector<int> nums3 = {1, 2, 2};
    cout << solution.minPatches(nums3, 5) << endl;  // Output: 0
    
    return 0;
}
How it works:

Greedy Approach:
miss: represents the smallest number we can't form yet
At each step, we either:
Use the next number from array if it's ≤ miss
Patch with miss itself if we can't use array number
Key Insight:
If we can form all numbers up to x-1, adding a number ≤ x extends our range
If we can't use an array number, patching with miss doubles our range
This is optimal because any smaller patch wouldn't cover miss
Algorithm:
Start with miss = 1
While miss ≤ n:
If we can use nums[i] (≤ miss): add it to miss, move to next number
Otherwise: patch with miss, increment patches
Return number of patches needed
Example Walkthrough for [1,3], n=6:
miss=1, nums[0]=1 ≤ 1: miss=2
miss=2, nums[1]=3 > 2: patch 2, miss=4
miss=4, nums[1]=3 ≤ 4: miss=7
miss=7 > 6: done
Patches = 1
Complexity:

Time Complexity: O(k + log n) where k is nums.length
We process each array element once
Each patch at least doubles miss, so O(log n) patches
Space Complexity: O(1) - only use constant extra space
Key Features:

Uses long to handle large sums up to 2^31-1
Works with sorted input array
Returns minimum number of patches needed
The solution satisfies all constraints:

Works for array length 1 to 1000
Handles array values 1 to 10^4
Works for n up to 2^31-1
For the examples:

[1,3], n=6 → 1 patch (need 2)
[1,5,10], n=20 → 2 patches (need 2,4)
[1,2,2], n=5 → 0 patches (can form 1-5 already)