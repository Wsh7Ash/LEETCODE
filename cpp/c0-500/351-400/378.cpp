#include <vector>
#include <iostream>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];           // smallest possible value
        int right = matrix[n-1][n-1];      // largest possible value
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countLessOrEqual(matrix, mid);
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    // Count elements less than or equal to target in the matrix
    int countLessOrEqual(std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1;  // start from bottom-left
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;  // all elements in this column up to this row
                col++;             // move right
            } else {
                row--;             // move up
            }
        }
        
        return count;
    }
};

// Test code
int main() {
    Solution sol;
    
    // Test case 1
    std::vector<std::vector<int>> matrix1 = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k1 = 8;
    std::cout << sol.kthSmallest(matrix1, k1) << std::endl;  // Should print 13
    
    // Test case 2
    std::vector<std::vector<int>> matrix2 = {{-5}};
    int k2 = 1;
    std::cout << sol.kthSmallest(matrix2, k2) << std::endl;  // Should print -5
    
    return 0;
}
This solution uses a binary search approach on the value range rather than the matrix indices. Here's how it works:

Approach:
Since the matrix is sorted in both rows and columns, we can use binary search
Instead of searching for indices, we search for the value itself
For each mid value, we count how many elements are less than or equal to it
Main Algorithm:
Search range: from smallest (top-left) to largest (bottom-right) element
For each mid value:
Count elements ≤ mid
If count < k: search in upper half
If count ≥ k: search in lower half
When left == right, we've found our answer
countLessOrEqual Helper:
Starts from bottom-left corner
Uses the sorted property:
If current element ≤ target: all elements above it in same column are too
If current element > target: move up
If current element ≤ target: move right and add count
Time complexity: O(n) as we traverse at most 2n steps
Complexity:
Time Complexity: O(n * log(M)) where:
n is the matrix dimension
M is the range of values (max - min)
log(M) iterations of binary search
O(n) for each count operation
Space Complexity: O(1) - only uses constant extra space
Example Walkthrough (matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8):
text

Collapse

Wrap

Copy
Initial: left = 1, right = 15
mid = 8: count = 3 < 8, left = 9
mid = 12: count = 6 < 8, left = 13
mid = 14: count = 8 ≥ 8, right = 14
mid = 13: count = 8 ≥ 8, right = 13
left = right = 13
Key Features:

Handles duplicates (returns kth smallest, not kth distinct)
Works with negative numbers
Meets space complexity requirement of better than O(n²)
Works within all given constraints
The solution efficiently finds the kth smallest element by leveraging the sorted property of the matrix without needing to flatten it or use a heap, which would require O(n²) space.