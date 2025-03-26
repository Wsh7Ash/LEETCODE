#include <vector>
#include <set>
#include <utility>

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // Use set to track corner points
        set<pair<int, int>> corners;
        
        // Calculate total area and find bounds
        long long totalArea = 0;  // Use long long to prevent overflow
        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;
        
        for (const auto& rect : rectangles) {
            int x1 = rect[0];  // Bottom-left x
            int y1 = rect[1];  // Bottom-left y
            int x2 = rect[2];  // Top-right x
            int y2 = rect[3];  // Top-right y
            
            // Calculate area of current rectangle
            totalArea += (long long)(x2 - x1) * (y2 - y1);
            
            // Update bounds
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
            
            // Add/remove corners to/from set
            pair<int, int> p1 = {x1, y1};  // Bottom-left
            pair<int, int> p2 = {x1, y2};  // Top-left
            pair<int, int> p3 = {x2, y1};  // Bottom-right
            pair<int, int> p4 = {x2, y2};  // Top-right
            
            // If point exists, remove it; if not, add it
            for (const auto& p : {p1, p2, p3, p4}) {
                if (corners.count(p)) {
                    corners.erase(p);
                } else {
                    corners.insert(p);
                }
            }
        }
        
        // Check if total area matches bounding rectangle area
        long long boundingArea = (long long)(maxX - minX) * (maxY - minY);
        if (totalArea != boundingArea) {
            return false;
        }
        
        // For perfect rectangle cover:
        // 1. Only 4 corners should remain (the outer bounds)
        // 2. They should match the min/max coordinates
        if (corners.size() != 4) {
            return false;
        }
        
        // Verify the remaining corners are the outer bounds
        return corners.count({minX, minY}) &&
               corners.count({minX, maxY}) &&
               corners.count({maxX, minY}) &&
               corners.count({maxX, maxY});
    }
};
How this solution works:

Key Principles:
For a perfect rectangle cover:
Total area of all rectangles = Area of bounding rectangle
All internal corners should cancel out (appear even number of times)
Only 4 outer corners should remain (appear once)
Algorithm:
Track all corner points in a set
If a corner appears twice, it gets removed (cancels out)
Calculate total area of all rectangles
Track min/max coordinates to determine bounding rectangle
Validate final conditions
Validation Checks:
Total area must equal bounding rectangle area (no gaps/overlaps)
Exactly 4 corners must remain
Remaining corners must be the outer bounds
Time and Space Complexity:
Time: O(n) where n is number of rectangles
Space: O(n) for the set of corners
Example Walkthrough (Example 1):
text

Collapse

Wrap

Copy
Input: [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
- Total area = 8
- Bounds: minX=1, minY=1, maxX=4, maxY=4
- Bounding area = 3 * 3 = 9
- Corners process:
  - Most internal corners cancel out
  - Remaining: {(1,1), (1,4), (4,1), (4,4)}
- Returns true
Handling Edge Cases:
Uses long long for area to prevent integer overflow
Works with negative coordinates
Handles single rectangle case
The solution correctly identifies:

Perfect covers (Example 1)
Gaps (Example 2)
Overlaps (Example 3)
It satisfies all constraints:

Handles 1 to 2*10^4 rectangles
Works with coordinates in range [-10^5, 10^5]
Assumes x1 < x2 and y1 < y2 as per problem definition