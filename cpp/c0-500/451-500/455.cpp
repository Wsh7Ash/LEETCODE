#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // Sort both arrays in ascending order
        std::sort(g.begin(), g.end());  // Sort greed factors
        std::sort(s.begin(), s.end());  // Sort cookie sizes
        
        int contentChildren = 0;
        int childIndex = 0;
        int cookieIndex = 0;
        
        // Iterate until we run out of either children or cookies
        while (childIndex < g.size() && cookieIndex < s.size()) {
            // If current cookie can satisfy current child
            if (s[cookieIndex] >= g[childIndex]) {
                contentChildren++;
                childIndex++;    // Move to next child
                cookieIndex++;   // Move to next cookie
            } else {
                cookieIndex++;   // Try next cookie for this child
            }
        }
        
        return contentChildren;
    }
};
Let's break down how this solution works:

Approach:
Sort both arrays to optimize cookie assignment
Use smallest cookies to satisfy children with smallest greed factors
This greedy approach maximizes the number of content children
Algorithm:
Sort greed factors (g) and cookie sizes (s)
Use two pointers: one for children, one for cookies
For each iteration:
If current cookie size ≥ current greed factor:
Increment count and move both pointers
If cookie too small:
Move to next cookie only
Time Complexity: O(n log n)
Sorting takes O(n log n) where n is max(g.length, s.length)
Single pass through arrays is O(n)
Total: O(n log n)
Space Complexity: O(1)
Only using a few variables, no extra data structures
Example 1: g = [1,2,3], s = [1,1]

Sorted: g = [1,2,3], s = [1,1]
child=0, cookie=0: 1≥1 ✓ (count=1)
child=1, cookie=1: 1<2 ✗ (next cookie)
Out of cookies
Result: 1
Example 2: g = [1,2], s = [1,2,3]

Sorted: g = [1,2], s = [1,2,3]
child=0, cookie=0: 1≥1 ✓ (count=1)
child=1, cookie=1: 2≥2 ✓ (count=2)
Result: 2
The solution handles all constraints:

Works for array lengths between 1 and 3×10⁴
Handles values between 1 and 2³¹-1
Each child gets at most one cookie
Maximizes number of content children
This greedy approach is optimal because:

Using smallest possible cookies for each child leaves larger cookies for children with larger greed factors
Sorting ensures we never waste a cookie that could have satisfied an earlier child
Single pass after sorting makes it efficient