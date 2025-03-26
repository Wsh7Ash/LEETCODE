#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int minLength = n + 1;  // Start with an impossible large value
    int left = 0, currentSum = 0;
    
    for (int right = 0; right < n; ++right) {
        currentSum += nums[right];  // Expand the window by adding nums[right]
        
        // When the sum is >= target, try to shrink the window
        while (currentSum >= target) {
            minLength = min(minLength, right - left + 1);
            currentSum -= nums[left];  // Shrink the window from the left
            left++;
        }
    }
    
    // If minLength was updated, return the result; otherwise, return 0
    return minLength <= n ? minLength : 0;
}

// Example usage:
int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    
    cout << minSubArrayLen(target, nums) << endl;  // Output: 2
    
    return 0;
}
