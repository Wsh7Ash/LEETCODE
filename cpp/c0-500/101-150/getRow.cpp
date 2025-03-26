#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);  // Initialize the row with 1's
        
        for (int i = 1; i <= rowIndex / 2; ++i) {
            // Calculate the current element using the previous element
            row[i] = (long long)row[i - 1] * (rowIndex - i + 1) / i;
            row[rowIndex - i] = row[i];  // Symmetric property of Pascal's triangle
        }
        
        return row;
    }
};

void printRow(const vector<int>& row) {
    for (int val : row) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1
    int rowIndex = 3;
    vector<int> row = sol.getRow(rowIndex);
    printRow(row);  // Expected output: [1, 3, 3, 1]

    // Example 2
    rowIndex = 0;
    row = sol.getRow(rowIndex);
    printRow(row);  // Expected output: [1]

    // Example 3
    rowIndex = 1;
    row = sol.getRow(rowIndex);
    printRow(row);  // Expected output: [1, 1]

    return 0;
}
