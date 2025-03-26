#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        // Sort the hand to make it easier to handle duplicates
        sort(hand.begin(), hand.end());
        // Start DFS with memoization
        int result = dfs(board, hand);
        return result == INT_MAX ? -1 : result;
    }

private:
    // Memoization map to store intermediate results
    unordered_map<string, int> memo;

    int dfs(string board, string hand) {
        // If the board is empty, no more moves are needed
        if (board.empty()) return 0;

        // If we have already computed this state, return the result
        string key = board + "#" + hand;
        if (memo.count(key)) return memo[key];

        int result = INT_MAX;
        for (int i = 0; i <= board.size(); ++i) {
            for (int j = 0; j < hand.size(); ++j) {
                // Skip if the current ball in hand is the same as the previous one (to avoid duplicates)
                if (j > 0 && hand[j] == hand[j - 1]) continue;

                // Insert the ball from hand into the board
                string newBoard = board.substr(0, i) + hand[j] + board.substr(i);
                string newHand = hand.substr(0, j) + hand.substr(j + 1);

                // Remove consecutive balls of the same color
                newBoard = removeConsecutive(newBoard);

                // Recursively call DFS
                int steps = dfs(newBoard, newHand);
                if (steps != -1) {
                    result = min(result, steps + 1);
                }
            }
        }

        // If no valid solution is found, return -1
        memo[key] = (result == INT_MAX) ? -1 : result;
        return memo[key];
    }

    string removeConsecutive(string board) {
        int n = board.size();
        for (int i = 0, j = 0; i < n; ++i) {
            j = i;
            while (j < n && board[j] == board[i]) ++j;
            if (j - i >= 3) {
                board = board.substr(0, i) + board.substr(j);
                i = -1; // Reset to start checking from the beginning again
                n = board.size();
            }
        }
        return board;
    }
};