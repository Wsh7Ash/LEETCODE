class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        // Sort by width ascending, and when widths are equal, sort by height descending
        Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        
        // Now find LIS based on height
        int[] dp = new int[envelopes.length];
        int len = 0;
        
        for (int[] envelope : envelopes) {
            // Binary search to find position to insert current height
            int index = Arrays.binarySearch(dp, 0, len, envelope[1]);
            if (index < 0) {
                index = -(index + 1);
            }
            dp[index] = envelope[1];
            if (index == len) {
                len++;
            }
        }
        
        return len;
    }
}
Let's break down how this solution works:

Key Insights:
We need to find the longest sequence where both width and height increase
After sorting by width, it becomes a LIS problem on heights
When widths are equal, we can't use both envelopes, so we sort heights in descending order
Algorithm:
First, sort the envelopes array:
Primary sort: width ascending
Secondary sort: height descending (when widths are equal)
Then find LIS on the height values using binary search optimization
Why Sort Heights Descending?:
If two envelopes have same width (e.g., [5,4] and [5,6])
Sorting height descending ensures we only count one of them
Because we can't nest envelopes with same width regardless of height
Example Walkthrough:
text
Wrap
Copy
Input: [[5,4],[6,4],[6,7],[2,3]]

After sorting: [[2,3],[5,4],[6,7],[6,4]]
(notice [6,7] comes before [6,4] due to descending height sort)

LIS on heights [3,4,7,4]:
- dp[0] = 3  (len=1)
- dp[0] = 3, dp[1] = 4  (len=2)
- dp[0] = 3, dp[1] = 4, dp[2] = 7  (len=3)
- dp[0] = 3, dp[1] = 4, dp[2] = 7  (4 doesn't increase length)

Return: 3
Time Complexity:
Sorting: O(n log n)
Binary search for each envelope: O(n log n)
Total: O(n log n)
Space Complexity:
O(n) for the dp array
Why This Works:
Sorting by width ensures we only consider valid width sequences
Height descending sort handles duplicate widths correctly
Binary search finds the longest possible sequence efficiently
dp array maintains the smallest height that can end a sequence of each length
The solution handles all constraints:

Works for arrays of length 1 to 10^5
Handles width and height values from 1 to 10^5
Returns the maximum possible nesting sequence
Doesn't allow rotation (strictly follows w1 < w2 and h1 < h2 rule)
This is an optimal solution that combines sorting with a binary search LIS algorithm to achieve O(n log n) time complexity, which is much better than the O(n²) approach of standard dynamic programming.