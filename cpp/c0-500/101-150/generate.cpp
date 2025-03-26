#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        // Generate rows of Pascal's triangle
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize each row with 1's
            
            // Fill in the values for the middle elements
            for (int j = 1; j < i; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            
            result.push_back(row);  // Add the current row to the result
        }
        
        return result;
    }
};

void printPascal(vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    
    // Example 1
    int numRows = 5;
    vector<vector<int>> triangle = sol.generate(numRows);
    printPascal(triangle);  // Expected output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
    
    // Example 2
    numRows = 1;
    triangle = sol.generate(numRows);
    printPascal(triangle);  // Expected output: [[1]]
    
    return 0;
}
