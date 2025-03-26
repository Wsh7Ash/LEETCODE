class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int m = board.size(), n = board[0].size();
            if (m == 0 || n == 0) return; // Edge case: empty board
    
            // Helper function to perform DFS and mark boundary-connected 'O's
            function<void(int, int)> dfs = [&](int i, int j) {
                // If out of bounds or not an 'O', return
                if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
    
                board[i][j] = '#'; // Mark the cell to indicate it's connected to the boundary
                dfs(i + 1, j); // Down
                dfs(i - 1, j); // Up
                dfs(i, j + 1); // Right
                dfs(i, j - 1); // Left
            };
    
            // Step 1: Find and mark all 'O's connected to the boundary
            // Traverse the first and last column
            for (int i = 0; i < m; i++) {
                if (board[i][0] == 'O') dfs(i, 0);        // Left boundary
                if (board[i][n - 1] == 'O') dfs(i, n - 1); // Right boundary
            }
    
            // Traverse the first and last row
            for (int j = 0; j < n; j++) {
                if (board[0][j] == 'O') dfs(0, j);        // Top boundary
                if (board[m - 1][j] == 'O') dfs(m - 1, j); // Bottom boundary
            }
    
            // Step 2: Flip all remaining 'O's to 'X' (captured) and '#' back to 'O' (not captured)
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O') board[i][j] = 'X'; // This 'O' is fully surrounded, capture it
                    if (board[i][j] == '#') board[i][j] = 'O'; // Restore safe 'O's connected to the boundary
                }
            }
        }
    };
    