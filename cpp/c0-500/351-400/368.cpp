class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return vector<int>();
            
            // Sort the array
            sort(nums.begin(), nums.end());
            
            // dp[i] represents length of largest subset ending at index i
            vector<int> dp(n, 1);
            // prev[i] stores the previous index in the subset ending at i
            vector<int> prev(n, -1);
            
            int maxLen = 1;  // Length of largest subset
            int maxIndex = 0;  // Ending index of largest subset
            
            // Fill dp array
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    maxIndex = i;
                }
            }
            
            // Reconstruct the subset
            vector<int> result;
            while (maxIndex != -1) {
                result.push_back(nums[maxIndex]);
                maxIndex = prev[maxIndex];
            }
            
            return result;
        }
    };
    Key differences from the Java version and C++-specific notes:
    
    Syntax Changes:
    Uses vector<int> instead of List<Integer>
    Uses sort() from STL instead of Arrays.sort()
    Vector initialization with size and default value is different
    push_back() instead of add()
    Implementation Details:
    No need to explicitly create a new ArrayList for empty case
    STL vector handles dynamic sizing automatically
    Return type is directly vector<int> rather than converting from a list
    Key Features Remain Same:
    Still uses dynamic programming approach
    Maintains dp and prev arrays
    Sorts input array first
    Builds result by following prev pointers
    Time and Space Complexity:
    Remains O(n²) time complexity
    Remains O(n) space complexity
    Example Usage:
    cpp
    Wrap
    Copy
    int main() {
        Solution sol;
        vector<int> nums = {1, 2, 4, 8};
        vector<int> result = sol.largestDivisibleSubset(nums);
        // result will be [1, 2, 4, 8]
        return 0;
    }
    The C++ solution maintains the same algorithmic approach as the Java version but uses C++-specific constructs. It will produce the same results and meets all the problem constraints:
    
    Works for 1 ≤ nums.length ≤ 1000
    Handles numbers up to 2 * 10⁹
    Works with unique integers
    Returns a valid subset where all pairs are divisible
    The solution will return one of the possible largest subsets where every pair of elements satisfies the divisibility condition, with elements typically in ascending order due to the initial sorting (though the problem accepts any valid subset regardless of order).