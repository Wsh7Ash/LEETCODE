#include <vector>

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        
        // Iterate through each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Only count if current cell is 'X' and it's the head of a battleship
                // (no 'X' immediately above or to the left)
                if (board[i][j] == 'X' &&
                    (i == 0 || board[i-1][j] != 'X') &&
                    (j == 0 || board[i][j-1] != 'X')) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<char>> board1 = {
        {'X','.','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    };
    cout << solution.countBattleships(board1) << endl;  // Output: 2
    
    // Test case 2
    vector<vector<char>> board2 = {{'.'}};
    cout << solution.countBattleships(board2) << endl;  // Output: 0
    
    return 0;
}
Let's break down how this solution works:

Approach:
Instead of counting all cells of each battleship, we only count the "head" (top-left cell)
A cell is a head if it's 'X' and has no 'X' immediately above or to its left
This works because:
Battleships are either horizontal or vertical
No battleships are adjacent
Each battleship has exactly one head
Algorithm:
Check if board is empty
Iterate through each cell
Count cell as battleship head if:
It's 'X'
No 'X' above it (or it's first row)
No 'X' to left (or it's first column)
Key Features:
Single pass through the board
No extra space needed
Time Complexity: O(m*n)
Space Complexity: O(1)
Example Walkthrough for [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]:
text

Collapse

Wrap

Copy
[0,0]: 'X', no above, no left -> count=1
[0,3]: 'X', no above, no 'X' left -> count=2
[1,3]: 'X', 'X' above -> skip
[2,3]: 'X', 'X' above -> skip
Result: 2 battleships
Why it works:
For horizontal ships: only leftmost 'X' is counted
For vertical ships: only topmost 'X' is counted
No adjacent ships ensures no false positives
The solution handles all constraints:

Works for m,n from 1 to 200
Only processes 'X' and '.' characters
Correctly counts non-adjacent horizontal/vertical battleships
This approach is optimal because:

Uses no extra space beyond input
Single pass through the board
Simple condition to identify battleship heads
Doesn't modify the input board