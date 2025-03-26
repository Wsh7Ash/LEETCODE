class Solution {
    public:
        bool canCross(vector<int>& stones) {
            int n = stones.size();
            
            // Map to store possible jump sizes from each stone
            unordered_map<int, unordered_set<int>> dp;
            
            // Initialize dp map with stone positions
            for (int stone : stones) {
                dp[stone] = unordered_set<int>();
            }
            
            // First jump must be 1 from stone 0
            dp[stones[0]].insert(0);
            dp[stones[1]].insert(1);
            
            // Process each stone
            for (int i = 0; i < n; i++) {
                int currentStone = stones[i];
                
                // For each possible jump size from current stone
                for (int jump : dp[currentStone]) {
                    // Try all possible next jumps (k-1, k, k+1)
                    for (int nextJump : {jump-1, jump, jump+1}) {
                        if (nextJump > 0) {  // Jump must be positive
                            int nextStone = currentStone + nextJump;
                            if (dp.find(nextStone) != dp.end()) {
                                dp[nextStone].insert(nextJump);
                            }
                        }
                    }
                }
            }
            
            // Can cross if last stone has any possible jumps
            return !dp[stones[n-1]].empty();
        }
    };
    How this solution works:
    
    Approach:
    Use DP with a hash map to track possible jump sizes
    For each stone position, store set of jump sizes that can reach it
    Build solution incrementally from first stone
    Key Components:
    dp: Map from stone position to set of possible jump sizes
    First jump must be 1 unit
    For each jump k, next can be k-1, k, or k+1
    Algorithm:
    Initialize dp map with all stone positions
    Start with jump 1 from stone 0
    For each stone and its jump sizes:
    Try all possible next jumps
    If next position is a stone, record the jump size
    Check if last stone is reachable
    Example Walkthrough (stones = [0,1,3,5,6,8,12,17]):
    text
    
    Collapse
    
    Wrap
    
    Copy
    dp[0] = {0}
    dp[1] = {1}
    From 1 (jump=1): 
    - 1+0=1, 1+1=2, 1+2=3 → dp[3]={2}
    From 3 (jump=2):
    - 3+1=4, 3+2=5, 3+3=6 → dp[5]={2}, dp[6]={3}
    ...
    Eventually reaches 17
    Complexity:
    Time: O(n * k) where n is number of stones, k is average jump sizes per stone
    Space: O(n * k) for the dp map
    In practice, k is bounded by stone distances
    Key Features:
    Handles first jump requirement
    Only allows forward jumps
    Efficiently tracks all possible paths
    The solution satisfies all constraints:
    
    Works for stones.length from 2 to 2000
    Handles stone positions up to 2³¹-1
    Assumes stones[0] = 0 and strictly increasing
    Alternative Solution (DP with array):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        bool canCross(vector<int>& stones) {
            int n = stones.size();
            // dp[i][j] = can reach stone i with jump j
            vector<vector<bool>> dp(n, vector<bool>(n+1, false));
            
            dp[0][0] = true;
            dp[1][1] = true;
            
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int diff = stones[i] - stones[j];
                    if (diff > i + 1) continue;  // Too far to jump
                    
                    for (int k : {diff-1, diff, diff+1}) {
                        if (k >= 0 && k <= n && dp[j][k]) {
                            dp[i][diff] = true;
                            if (i == n-1) return true;
                        }
                    }
                }
            }
            
            return false;
        }
    };
    The hash map solution is preferred because:
    
    More space-efficient for sparse data
    Easier to understand and maintain
    Better performance with large gaps between stones
    Both solutions correctly handle:
    
    Example 1: [0,1,3,5,6,8,12,17] → true
    Example 2: [0,1,2,3,4,8,9,11] → false
    The solution efficiently determines reachability while respecting all jump rules and constraints of the problem.