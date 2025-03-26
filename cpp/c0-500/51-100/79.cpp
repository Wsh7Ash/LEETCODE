#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Directions for moving up, down, left, and right
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool backtrack(int i, int j, const vector<vector<char>>& board, const string& word, int index) {
    // If we have matched the whole word, return true
    if (index == word.length()) return true;
    
    // If out of bounds or the current cell does not match the character in word
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
        return false;
    }

    // Temporarily mark the current cell as visited
    char temp = board[i][j];
    board[i][j] = '#';  // Use '#' as a marker for visited cells

    // Explore all 4 directions (up, down, left, right)
    for (auto& dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        
        if (backtrack(new_i, new_j, board, word, index + 1)) {
            return true;
        }
    }

    // Revert the visited cell
    board[i][j] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || word.empty()) return false;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            // Start the backtracking if the first character matches
            if (board[i][j] == word[0] && backtrack(i, j, board, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    
    if (exist(board, word)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found." << endl;
    }

    return 0;
}
