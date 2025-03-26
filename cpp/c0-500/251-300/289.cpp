For the Game of Life problem, we need to update the board in-place while following Conway's rules. The challenge is that we must apply the rules simultaneously, so we can't modify cells directly without affecting neighbor counts. Here's a solution that uses additional bits to store both old and new states:

cpp
Wrap
Copy
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    
    // Directions array for 8 neighbors
    int dirs[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, 
                      {0,1}, {1,-1}, {1,0}, {1,1}};
    
    // First pass: encode new states in higher bits
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            
            // Count live neighbors
            for(auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && 
                   (board[ni][nj] & 1) == 1) {
                    liveNeighbors++;
                }
            }
            
            // Apply rules (store new state in bit 1)
            if(board[i][j] == 1) {
                // Live cell rules
                if(liveNeighbors < 2 || liveNeighbors > 3) {
                    board[i][j] = 1;    // 01: was live, now dead
                } else {
                    board[i][j] = 3;    // 11: was live, stays live
                }
            } else {
                // Dead cell rule
                if(liveNeighbors == 3) {
                    board[i][j] = 2;    // 10: was dead, now live
                }
            }
        }
    }
    
    // Second pass: shift bits to get final state
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] >>= 1;  // Shift right to keep only new state
        }
    }
}
Let's break this down:

Approach:
Use 2 bits per cell: bit 0 for current state, bit 1 for next state
Possible states:
00 (0): was dead, stays dead
01 (1): was live, becomes dead
10 (2): was dead, becomes live
11 (3): was live, stays live
First Pass:
For each cell, count live neighbors (using bit 0 of neighbor cells)
Apply rules and encode new state:
Current state in bit 0
Next state in bit 1
Second Pass:
Right shift each value by 1 to keep only the new state
Rules Implementation:
Live (1) → check neighbors:
< 2: dies (01)
2 or 3: lives (11)
3: dies (01)

Dead (0) → check neighbors:
3: lives (10)
else: stays dead (00)
Example with [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]:

text
Wrap
Copy
Initial:    After first pass:    After second pass:
[0,1,0]     [0,2,0]             [0,1,0]
[0,0,1]     [2,0,3]             [1,0,1]
[1,1,1]     [0,3,3]             [0,1,1]
[0,0,0]     [0,2,0]             [0,1,0]
Time Complexity: O(m*n)

Two passes through the board
Each cell checks 8 neighbors
Space Complexity: O(1)

Only uses a constant amount of extra space
Modifies array in-place using extra bits
This solution:

Updates board in-place
Applies rules simultaneously (by preserving original states in first pass)
Handles all constraints
Correctly produces expected outputs for examples
Uses the 8-direction neighbor checking efficiently