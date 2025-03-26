#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Initialize first and second numbers of triplet
        int first = INT_MAX;  // Smallest number seen so far
        int second = INT_MAX; // Second smallest number seen so far
        
        // Iterate through the array
        for (int num : nums) {
            // Update first if we find a smaller number
            if (num <= first) {
                first = num;
            }
            // Update second if we find a number bigger than first but smaller than second
            else if (num <= second) {
                second = num;
            }
            // If we find a number bigger than both first and second, we have a triplet
            else {
                return true;
            }
        }
        
        return false;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << boolalpha << solution.increasingTriplet(nums1) << endl;  // true
    
    // Test case 2
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << solution.increasingTriplet(nums2) << endl;  // false
    
    // Test case 3
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    cout << solution.increasingTriplet(nums3) << endl;  // true
    
    return 0;
}
How it works:

Greedy Approach:
We maintain two variables: first and second
first: smallest number seen so far
second: second smallest number that's greater than first
Algorithm:
For each number in the array:
If it's smaller than or equal to first, update first
Else if it's smaller than or equal to second but greater than first, update second
Else if it's greater than both first and second, we found a valid triplet
If we complete the loop without finding a third number, return false
Key Insight:
Even if we update first to a smaller value after setting second, the fact that we found a second larger than an earlier first means we have a valid increasing pair
We just need one more number larger than second to complete the triplet
Example Walkthrough for [2,1,5,0,4,6]:
2: first=2, second=INT_MAX
1: first=1, second=INT_MAX
5: first=1, second=5
0: first=0, second=5
4: first=0, second=4
6: 6 > second(4): return true
Complexity:

Time Complexity: O(n) - single pass through the array
Space Complexity: O(1) - only using two variables
Key Features:

Doesn't need to find exact indices
Works with duplicates
Handles negative numbers
Returns as soon as a valid triplet is found
The solution satisfies all constraints:

Works for array length 1 to 5 * 10^5
Handles values from -2^31 to 2^31-1
For the examples:

[1,2,3,4,5] → true (1,2,3 or any other triplet)
[5,4,3,2,1] → false (no increasing triplet)
[2,1,5,0,4,6] → true (0,4,6)
This solution is efficient because:

It only requires one pass
Uses constant extra space
Doesn't need to store the actual triplet
Handles edge cases naturally