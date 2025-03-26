#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Start from the second last row and move upwards
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                // Update the current element by adding the minimum of the two adjacent numbers from the row below
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }

        // The result is now at the top of the triangle
        return triangle[0][0];
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> triangle1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum for triangle 1: " << sol.minimumTotal(triangle1) << endl; // Expected output: 11

    // Example 2
    vector<vector<int>> triangle2 = {{-10}};
    cout << "Minimum path sum for triangle 2: " << sol.minimumTotal(triangle2) << endl; // Expected output: -10

    return 0;
}
