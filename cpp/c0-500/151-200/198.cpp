#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n);
    dp[0] = nums[0];  // Base case: Only one house to rob
    dp[1] = max(nums[0], nums[1]);  // Base case: Rob the max of the first two houses
    
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    }
    
    return dp[n-1];  // Maximum money that can be robbed
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;  // Output: 12
    return 0;
}
