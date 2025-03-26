// cpp
// Wrap
// Copy
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Step 1: Create events for building start and end points
        vector<pair<int, int>> events;  // {x, height} where height is +h for start, -h for end
        for (auto& building : buildings) {
            int left = building[0], right = building[1], height = building[2];
            events.push_back({left, height});    // Start event
            events.push_back({right, -height});  // End event
        }
        
        // Sort events by x-coordinate
        // If same x, sort by height (start before end, taller first)
        sort(events.begin(), events.end(), 
             [](pair<int, int>& a, pair<int, int>& b) {
                 if (a.first != b.first) return a.first < b.first;
                 return a.second > b.second;
             });
        
        // Step 2: Process events using a multiset for heights
        multiset<int> heights;  // Tracks active building heights
        heights.insert(0);     // Ground level
        vector<vector<int>> result;
        int prevHeight = 0;
        
        for (auto& event : events) {
            int x = event.first;
            int h = event.second;
            
            // Process event
            if (h > 0) {  // Start of building
                heights.insert(h);
            } else {      // End of building
                heights.erase(heights.find(-h));
            }
            
            // Check if height changes
            int currHeight = *heights.rbegin();  // Max height
            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        
        return result;
    }
};
// Let's break down how this solution works:

// Approach:
// Use sweep line algorithm
// Convert buildings into start/end events
// Process events in order, tracking max height
// Record key points when height changes
// Key Components:
// a. Event Creation:

// For each building: [left, right, height]
// Create start event: [left, +height]
// Create end event: [right, -height]
// b. Event Sorting:

// Sort by x-coordinate
// For same x: start events before end events
// For same x starts: taller first
// c. Height Tracking:

// Use multiset to maintain active heights
// Include 0 for ground level
// Add height at start, remove at end
// Algorithm:

// text
// Wrap
// Copy
// 1. Convert buildings to events
// 2. Sort events by x-coordinate
// 3. Process events:
//    - Start: add height
//    - End: remove height
//    - Record point if max height changes
// Example Walkthrough:
// text
// Wrap
// Copy
// Input: [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// Events: [[2,10],[3,15],[5,12],[7,-15],[9,-10],[12,-12],[15,10],[19,8],[20,-10],[24,-8]]
// Processing:
// - [2,10]: heights={0,10} -> [[2,10]]
// - [3,15]: heights={0,10,15} -> [[2,10],[3,15]]
// - [5,12]: heights={0,10,12,15}
// - [7,-15]: heights={0,10,12} -> [[2,10],[3,15],[7,12]]
// - [9,-10]: heights={0,12}
// - [12,-12]: heights={0} -> [[2,10],[3,15],[7,12],[12,0]]
// - [15,10]: heights={0,10} -> [[2,10],[3,15],[7,12],[12,0],[15,10]]
// - [19,8]: heights={0,8,10}
// - [20,-10]: heights={0,8} -> [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8]]
// - [24,-8]: heights={0} -> [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
// Complexity:
// Time: O(n log n)
// Sorting events: O(n log n)
// Processing with multiset: O(n log n)
// Space: O(n)
// Events array: O(n)
// Heights multiset: O(n)
// Correctness:
// Handles overlapping buildings
// Merges consecutive same-height segments
// Ends with height 0
// Produces sorted key points
// Captures all height changes
// Meets constraints:

// 1 <= buildings.length <= 10^4
// 0 <= lefti < righti <= 2^31 - 1
// 1 <= heighti <= 2^31 - 1
// The sweep line approach is optimal because:

// Processes each building edge exactly once
// Maintains active heights efficiently
// Naturally produces sorted output
// Handles all edge cases correctly