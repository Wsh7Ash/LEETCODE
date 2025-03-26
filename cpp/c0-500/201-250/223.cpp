Let's solve the "Rectangle Area" problem in C++. This involves calculating the total area of two rectangles, accounting for any overlap between them. Here's the solution:

cpp
Wrap
Copy
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, 
                   int bx1, int by1, int bx2, int by2) {
        // Calculate area of first rectangle
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        
        // Calculate area of second rectangle
        int area2 = (bx2 - bx1) * (by2 - by1);
        
        // Calculate overlap dimensions
        int overlapWidth = std::min(ax2, bx2) - std::max(ax1, bx1);
        int overlapHeight = std::min(ay2, by2) - std::max(ay1, by1);
        
        // Calculate overlap area (if there is overlap)
        int overlapArea = 0;
        if (overlapWidth > 0 && overlapHeight > 0) {
            overlapArea = overlapWidth * overlapHeight;
        }
        
        // Total area = area1 + area2 - overlap
        return area1 + area2 - overlapArea;
    }
};
// Let's break down how this solution works:

// Approach:
// Calculate the area of each rectangle separately
// Calculate the overlapping area (if any)
// Return the sum of individual areas minus the overlap
// Key Steps:
// Rectangle area = width × height
// Width = right_x - left_x
// Height = top_y - bottom_y
// Overlap exists only if overlapWidth and overlapHeight are both positive
// Overlap Calculation:
// overlapWidth = min(right edges) - max(left edges)
// overlapHeight = min(top edges) - max(bottom edges)
// If either dimension is ≤ 0, there's no overlap
// Time and Space Complexity:
// Time Complexity: O(1) - constant time operations
// Space Complexity: O(1) - constant extra space
// Example 1 Walkthrough:
// text
// Wrap
// Copy
// Input: ax1=-3, ay1=0, ax2=3, ay2=4, bx1=0, by1=-1, bx2=9, by2=2

// - area1 = (3 - (-3)) * (4 - 0) = 6 * 4 = 24
// - area2 = (9 - 0) * (2 - (-1)) = 9 * 3 = 27
// - overlapWidth = min(3,9) - max(-3,0) = 3 - 0 = 3
// - overlapHeight = min(4,2) - max(0,-1) = 2 - 0 = 2
// - overlapArea = 3 * 2 = 6
// - total = 24 + 27 - 6 = 45
// Example 2 Walkthrough:
// text
// Wrap
// Copy
// Input: ax1=-2, ay1=-2, ax2=2, ay2=2, bx1=-2, by1=-2, bx2=2, by2=2
// (identical rectangles)

// - area1 = (2 - (-2)) * (2 - (-2)) = 4 * 4 = 16
// - area2 = (2 - (-2)) * (2 - (-2)) = 4 * 4 = 16
// - overlapWidth = min(2,2) - max(-2,-2) = 2 - (-2) = 4
// - overlapHeight = min(2,2) - max(-2,-2) = 2 - (-2) = 4
// - overlapArea = 4 * 4 = 16
// - total = 16 + 16 - 16 = 16
// The solution handles all cases correctly:

// When rectangles don't overlap (overlapArea = 0)
// When rectangles partially overlap
// When one rectangle contains another
// When rectangles are identical
// The code uses std::min and std::max for clarity, and the overlap check (width > 0 && height > 0) ensures we only subtract an overlap area when there actually is an overlap, avoiding negative areas in non-overlapping cases. This implementation meets all the constraints and provides accurate results for the given examples.