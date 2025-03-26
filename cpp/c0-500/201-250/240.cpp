#include <vector>
using namespace std;

class MatrixSearchSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int row = 0, col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col--; // Move left
            else row++; // Move down
        }
        
        return false;
    }
};
// Approach Explanation
// Start from the top-right corner of the matrix.
// If matrix[row][col] == target, return true.
// If matrix[row][col] > target, move left (col--).
// If matrix[row][col] < target, move down (row++).
// If we go out of bounds, return false.
// This approach runs in O(m + n) time complexity, making it efficient for large matrices.