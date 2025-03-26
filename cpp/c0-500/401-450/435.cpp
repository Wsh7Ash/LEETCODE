#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int count = 0;          // Number of intervals to remove
        int prevEnd = intervals[0][1];  // End time of last kept interval
        
        // Iterate through sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval starts before previous end, it's overlapping
            if (intervals[i][0] < prevEnd) {
                count++;  // Need to remove this interval
            } else {
                // No overlap, update prevEnd
                prevEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};
Let's break down how this solution works:

Approach:
Sort intervals by end time
Keep track of the last non-overlapping interval's end time
For each interval, if it overlaps with previous, increment removal count
If no overlap, update the last end time
Why Sort by End Time?:
By choosing intervals with earliest end times, we maximize the space available for subsequent intervals
This greedy choice leads to minimum removals
Algorithm Steps:
Sort intervals by end time
Take first interval as initial non-overlapping interval
For each subsequent interval:
If start time < previous end time: increment removal count
Else: update previous end time to current end time
Return total removals needed
Example 1: [[1,2],[2,3],[3,4],[1,3]]
Sort by end: [[1,2],[2,3],[1,3],[3,4]]
prevEnd = 2
[2,3]: no overlap (2 ≥ 2), prevEnd = 3
[1,3]: overlap (1 < 3), count = 1
[3,4]: no overlap (3 ≥ 3), prevEnd = 4
Return 1
Time and Space Complexity:
Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) as we modify input array in-place
Key Features:
Handles touching intervals correctly (e.g., [1,2] and [2,3] don't overlap)
Works with empty input
Efficiently finds minimum removals
Constraints Handling:
Works for 1 ≤ length ≤ 10^5
Handles intervals of length 2
Works with range -5 * 10^4 ≤ start < end ≤ 5 * 10^4
The solution is optimal because:

Sorting by end time ensures we keep as many intervals as possible
We only remove intervals when necessary (when they overlap with our kept set)
The greedy choice of keeping earliest-ending intervals minimizes conflicts with future intervals