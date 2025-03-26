Approaches:
Dynamic Programming with Binary Search:

Maintain a list dp where dp[i] represents the smallest ending element of all increasing subsequences of length i+1.

Iterate through each number in nums and use binary search to find the position at which the number can be inserted into dp to maintain the sorted order.

If the number is greater than all elements in dp, append it to dp. Otherwise, replace the first element in dp that is greater than or equal to the number.

The length of dp at the end of the iteration is the length of the longest increasing subsequence.

Time Complexity:

O
(
n
log
⁡
n
)
O(nlogn), where 
n
n is the length of nums.

Space Complexity:

O
(
n
)
O(n), for the dp list.

Solution Code:
cpp
Copy
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp; // dp[i] = smallest ending element of all increasing subsequences of length i+1

        for (int num : nums) {
            // Find the position to insert num in dp
            auto it = lower_bound(dp.begin(), dp.end(), num);

            if (it == dp.end()) {
                // num is greater than all elements in dp, so append it
                dp.push_back(num);
            } else {
                // Replace the first element >= num with num
                *it = num;
            }
        }

        // The length of dp is the length of the longest increasing subsequence
        return dp.size();
    }
};
Explanation:
Initialization:

Start with an empty dp list.

Iterate Through nums:

For each number num in nums, use lower_bound to find the position where num can be inserted into dp while maintaining the sorted order.

lower_bound returns an iterator to the first element in dp that is not less than num.

Update dp:

If num is greater than all elements in dp, append it to dp.

Otherwise, replace the first element in dp that is greater than or equal to num with num.

Result:

The length of dp at the end of the iteration is the length of the longest increasing subsequence.

Example Walkthrough:
Input:
cpp
Copy
nums = [10, 9, 2, 5, 3, 7, 101, 18]
Execution:
Initialize dp = [].

Process 10:

dp = [10].

Process 9:

Replace 10 with 9: dp = [9].

Process 2:

Replace 9 with 2: dp = [2].

Process 5:

Append 5: dp = [2, 5].

Process 3:

Replace 5 with 3: dp = [2, 3].

Process 7:

Append 7: dp = [2, 3, 7].

Process 101:

Append 101: dp = [2, 3, 7, 101].

Process 18:

Replace 101 with 18: dp = [2, 3, 7, 18].

Output:
cpp
Copy
4
Key Points:
Efficiency:

The use of lower_bound ensures that the time complexity is 
O
(
n
log
⁡
n
)
O(nlogn).

Space Optimization:

The dp list only stores the smallest ending elements of increasing subsequences, making it space-efficient.

Correctness:

The algorithm ensures that the length of dp always represents the length of the longest increasing subsequence.

Output for Other Test Cases:
Input:
cpp
Copy
nums = [0, 1, 0, 3, 2, 3]
Execution:
dp = [0]

dp = [0, 1]

dp = [0, 1] (no change)

dp = [0, 1, 3]

dp = [0, 1, 2]

dp = [0, 1, 2, 3]

Output:
cpp
Copy
4
Input:
cpp
Copy
nums = [7, 7, 7, 7, 7, 7, 7]
Execution:
dp = [7] (no changes for subsequent elements)

Output:
cpp
Copy
1
This solution is efficient and handles all edge cases, making it suitable for the given problem constraints.