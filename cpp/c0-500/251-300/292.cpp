Let's solve the Nim Game problem. This is a classic game theory problem where we can find a mathematical pattern to determine the winning strategy.

The key insight is that if the number of stones is a multiple of 4, the first player (you) will lose if both players play optimally. Here's the solution:

cpp
Wrap
Copy
bool canWinNim(int n) {
    return n % 4 != 0;
}
Let's understand why this works:

Pattern Analysis:
n = 1: Take 1 stone → Win
n = 2: Take 2 stones → Win
n = 3: Take 3 stones → Win
n = 4: Any move (1,2,3) leaves 3,2,1 stones → Opponent can win
n = 5: Take 1 stone (leave 4) → Opponent loses
n = 6: Take 2 stones (leave 4) → Opponent loses
n = 7: Take 3 stones (leave 4) → Opponent loses
n = 8: Any move leaves 7,6,5 → Opponent can force a win
Key Insight:
When n % 4 == 0, second player can always win
When n % 4 != 0, first player can force a win by:
Taking stones to make the remainder 0 for opponent
Leaving opponent with a multiple of 4
Why modulo 4?
The game cycles every 4 stones
If you can leave your opponent with a multiple of 4 stones, they will eventually lose no matter how optimally they play
For Example 1 (n = 4):

You take 1 → 3 left → Opponent takes 3 → Wins
You take 2 → 2 left → Opponent takes 2 → Wins
You take 3 → 1 left → Opponent takes 1 → Wins
Returns false
For Example 2 (n = 1):

You take 1 → Win
Returns true
For Example 3 (n = 2):

You take 2 → Win
Returns true
Time Complexity: O(1)

Simple modulo operation
Space Complexity: O(1)

No extra space needed
This solution:

Assumes optimal play from both players
Correctly handles all test cases
Meets the constraint of 1 <= n <= 2³¹ - 1
Is extremely efficient
Uses the mathematical property of the game to determine the winner
The beauty of this solution lies in its simplicity - the entire game strategy boils down to checking if n is not divisible by 4, which determines if the first player can force a win.