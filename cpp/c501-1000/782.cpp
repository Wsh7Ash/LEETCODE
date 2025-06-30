class Solution {
    public:
        int movesToChessboard(vector<vector<int>>& board) {
            int n = board.size();
            
            map<vector<int>, int> rowCount, colCount;
            
            for (int i = 0; i < n; i++) {
                rowCount[board[i]]++;
            }
            
            for (int j = 0; j < n; j++) {
                vector<int> col;
                for (int i = 0; i < n; i++) {
                    col.push_back(board[i][j]);
                }
                colCount[col]++;
            }
            
            if (rowCount.size() != 2 || colCount.size() != 2) {
                return -1;
            }
            
            vector<vector<int>> rowPatterns;
            vector<int> rowCounts;
            for (auto& p : rowCount) {
                rowPatterns.push_back(p.first);
                rowCounts.push_back(p.second);
            }
            
            vector<vector<int>> colPatterns;
            vector<int> colCounts;
            for (auto& p : colCount) {
                colPatterns.push_back(p.first);
                colCounts.push_back(p.second);
            }
            
            if (!areComplements(rowPatterns[0], rowPatterns[1])) {
                return -1;
            }
            
            if (!areComplements(colPatterns[0], colPatterns[1])) {
                return -1;
            }
            
            if (abs(rowCounts[0] - rowCounts[1]) > 1) {
                return -1;
            }
            if (abs(colCounts[0] - colCounts[1]) > 1) {
                return -1;
            }
            
            int rowSwaps = calculateSwaps(board, true, n);
            if (rowSwaps == -1) return -1;
            
            int colSwaps = calculateSwaps(board, false, n);
            if (colSwaps == -1) return -1;
            
            return rowSwaps + colSwaps;
        }
        
    private:
        bool areComplements(const vector<int>& a, const vector<int>& b) {
            if (a.size() != b.size()) return false;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] + b[i] != 1) return false;
            }
            return true;
        }
        
        int calculateSwaps(vector<vector<int>>& board, bool isRow, int n) {
            vector<int> current;
            if (isRow) {
                for (int i = 0; i < n; i++) {
                    current.push_back(board[i][0]); 
                }
            } else {
                for (int j = 0; j < n; j++) {
                    current.push_back(board[0][j]); 
                }
            }
            
            vector<int> target1, target2;
            for (int i = 0; i < n; i++) {
                target1.push_back(i % 2);        
                target2.push_back((i + 1) % 2);  
            }
            
            int swaps1 = countSwaps(current, target1);
            int swaps2 = countSwaps(current, target2);
            
            int result = INT_MAX;
            if (swaps1 != -1) result = min(result, swaps1);
            if (swaps2 != -1) result = min(result, swaps2);
            
            return result == INT_MAX ? -1 : result;
        }
        
        int countSwaps(const vector<int>& current, const vector<int>& target) {
            int n = current.size();
            int mismatches = 0;
            
            for (int i = 0; i < n; i++) {
                if (current[i] != target[i]) {
                    mismatches++;
                }
            }
            
            if (mismatches % 2 != 0) {
                return -1;
            }
            
            return mismatches / 2;
        }
    };