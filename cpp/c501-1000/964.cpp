class Solution {
    public:
        int leastOpsExpressTarget(int x, int target) {
            unordered_map<int, int> memo;
            return dfs(target, x, memo);
        }
        
    private:
        int dfs(int target, int x, unordered_map<int, int>& memo) {
            if (x >= target) {
    
                return min(target * 2 - 1, 2 * (x - target));
            }
            
            if (memo.count(target)) return memo[target];
            
            int k = 2;
            long long power = (long long)x * x;
            while (power < target) {
                power *= x;
                k++;
            }
            
    
            int s1 = (k - 1) + dfs(target - power / x, x, memo);
            
            int s2 = INT_MAX;
            if (power - target < target) {
                s2 = k + dfs(power - target, x, memo);
            }
            
            return memo[target] = min(s1, s2);
        }
    };