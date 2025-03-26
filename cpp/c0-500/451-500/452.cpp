#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort by end coordinate
        std::sort(points.begin(), points.end(), 
                 [](const std::vector<int>& a, const std::vector<int>& b) {
                     return a[1] < b[1];
                 });
        
        int arrows = 1;  // We need at least one arrow
        int currentEnd = points[0][1];  // Take the first end point
        
        // Iterate through sorted balloons
        for (int i = 1; i < points.size(); i++) {
            // If current balloon starts after previous end point
            // We need a new arrow
            if (points[i][0] > currentEnd) {
                arrows++;
                currentEnd = points[i][1];
            }
            // If there's overlap, we keep the same arrow
            // and currentEnd stays the same since it's <= points[i][1]
        }
        
        return arrows;
    }
};
Let's break down how this solution works:

Base Case: If the input array is empty, return 0 as no arrows are needed.
Sorting: We sort the balloons by their end coordinates (xend). This allows us to process balloons in order of when they end, making it easier to find overlapping intervals.
Greedy Approach:
Start with 1 arrow for the first balloon
Keep track of the current end point (initially the end of first balloon)
For each subsequent balloon:
If it starts after the current end point (no overlap), we need a new arrow
If it overlaps with the current end point, we can use the same arrow
Time Complexity: O(n log n) due to the sorting operation Space Complexity: O(1) as we only use a constant amount of extra space
Let's verify with the examples:

Example 1: [[10,16],[2,8],[1,6],[7,12]]

Sort by end: [[1,6],[2,8],[7,12],[10,16]]
First arrow at 6 covers [1,6] and [2,8]
Second arrow at 12 covers [7,12] and [10,16]
Result: 2
Example 2: [[1,2],[3,4],[5,6],[7,8]]

No overlaps, each needs its own arrow
Result: 4
Example 3: [[1,2],[2,3],[3,4],[4,5]]

Sort: [[1,2],[2,3],[3,4],[4,5]]
First arrow at 2 covers [1,2] and [2,3]
Second arrow at 4 covers [3,4] and [4,5]
Result: 2