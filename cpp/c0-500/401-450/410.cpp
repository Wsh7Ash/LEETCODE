class Solution {
    public:
        int splitArray(vector<int>& nums, int k) {
            int left = 0;
            int right = 0;
            
            // Initialize search boundaries
            for (int num : nums) {
                left = max(left, num);      // Minimum possible result (max single element)
                right += num;              // Maximum possible result (sum of all elements)
            }
            
            // Binary search for the minimum largest sum
            while (left < right) {
                int mid = left + (right - left) / 2;
                
                // Count how many subarrays we can make with sum <= mid
                int count = 1;
                int currentSum = 0;
                
                for (int num : nums) {
                    if (currentSum + num <= mid) {
                        currentSum += num;
                    } else {
                        count++;
                        currentSum = num;
                    }
                }
                
                // Adjust search range based on count
                if (count <= k) {
                    right = mid;    // Try smaller maximum sum
                } else {
                    left = mid + 1; // Need larger maximum sum
                }
            }
            
            return left;
        }
    };
    How this solution works:
    
    Approach:
    Use binary search on the possible range of results
    For each potential maximum sum, count required subarrays
    Adjust search based on whether we can split into k or fewer subarrays
    Key Insight:
    Result must be between max element and total sum
    If we can split into ≤ k subarrays with sum X, we might do better
    If we need > k subarrays, we need larger maximum sum
    Algorithm:
    Set left = max element, right = total sum
    Binary search:
    Try mid as maximum sum
    Greedily count subarrays needed
    If count ≤ k: try smaller sum
    If count > k: try larger sum
    Converges to minimum valid largest sum
    Example Walkthrough (nums = [7,2,5,10,8], k = 2):
    text
    
    Collapse
    
    Wrap
    
    Copy
    left = 10 (max element), right = 32 (total sum)
    mid = 21:
    - [7,2,5] (14), [10,8] (18) → count=2 ≤ k → right=21
    mid = 15:
    - [7,2] (9), [5,10] (15), [8] → count=3 > k → left=16
    mid = 18:
    - [7,2,5] (14), [10,8] (18) → count=2 ≤ k → right=18
    left = right = 18
    Result: 18
    Complexity:
    Time: O(n * log(sum)) where n is array length, sum is sum of elements
    Space: O(1)
    Key Features:
    Handles non-empty subarray requirement
    Finds minimum largest sum
    Works with any valid k
    The solution satisfies all constraints:
    
    Works for nums.length from 1 to 1000
    Handles nums[i] from 0 to 10⁶
    Works for k from 1 to min(50, nums.length)
    Alternative DP Solution (less efficient):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            vector<vector<long>> dp(n + 1, vector<long>(k + 1, LONG_MAX));
            
            vector<long> prefixSum(n + 1, 0);
            for (int i = 0; i < n; i++) {
                prefixSum[i + 1] = prefixSum[i] + nums[i];
            }
            
            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= min(k, i); j++) {
                    for (int p = 0; p < i; p++) {
                        dp[i][j] = min(dp[i][j], 
                                     max(dp[p][j-1], prefixSum[i] - prefixSum[p]));
                    }
                }
            }
            
            return dp[n][k];
        }
    };
    The binary search solution is preferred because:
    
    Much better time complexity: O(n log(sum)) vs O(n²k)
    Simpler implementation
    No need for extra space
    Both solutions correctly handle:
    
    Example 1: [7,2,5,10,8], k=2 → 18
    Example 2: [1,2,3,4,5], k=2 → 9
    The binary search approach efficiently finds the optimal solution by narrowing down the possible range of maximum sums, making it practical for the given constraints.