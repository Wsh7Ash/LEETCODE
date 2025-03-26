#include <vector>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, 
                    std::vector<int>& nums3, std::vector<int>& nums4) {
        // Store sums of pairs from nums1 and nums2
        std::unordered_map<int, int> sumMap;
        int n = nums1.size();
        
        // Calculate all possible sums of nums1 and nums2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                sumMap[sum]++;
            }
        }
        
        int count = 0;
        // Check complementary sums from nums3 and nums4
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int target = -(nums3[k] + nums4[l]);
                if (sumMap.find(target) != sumMap.end()) {
                    count += sumMap[target];
                }
            }
        }
        
        return count;
    }
};
Let's break down how this solution works:

Approach:
Instead of checking all O(n⁴) combinations, we split into two O(n²) problems
Store all possible sums of pairs from nums1 and nums2 in a hash map
For each pair from nums3 and nums4, look for complementary sum that makes total = 0
Algorithm:
First loop: Build hash map of sums from nums1 + nums2
Key: sum value
Value: frequency of that sum
Second loop: For each sum of nums3 + nums4
Calculate complementary value needed (-sum)
Add frequency of that value from hash map to count
Time Complexity: O(n²)
Two nested loops for first pair: O(n²)
Two nested loops for second pair: O(n²)
Hash map operations are O(1) on average
Space Complexity: O(n²)
Hash map stores at most n² different sums
Example 1: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]

First phase (sums in map):
1 + (-2) = -1 (count: 1)
1 + (-1) = 0 (count: 1)
2 + (-2) = 0 (count: 2)
2 + (-1) = 1 (count: 1)
Second phase:
-1 + 0 = -1 needs 1 (found, count += 1)
-1 + 2 = 1 needs -1 (not found)
2 + 0 = 2 needs -2 (not found)
2 + 2 = 4 needs -4 (not found)
Result: 2
Example 2: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]

Map: {0:1}
Check: 0 + 0 = 0 needs 0 (found, count += 1)
Result: 1
The solution handles all constraints:

Works for n between 1 and 200
Handles values between -2²⁸ and 2²⁸
Uses int for count which is sufficient as maximum possible count is n⁴ ≤ 200⁴ < 2³¹