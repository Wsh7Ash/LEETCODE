class Solution {
    public:
        double soupServings(int n) {
            if(n >= 4800) return 1.0;
            unordered_map<int, unordered_map<int, double>> memo;
            return helper(n, n, memo);
        }
    
        double helper(int a, int b, unordered_map<int, unordered_map<int, double>>& memo){
            if(a <= 0 && b <= 0) return 0.5;
            if(a <= 0) return 1.0;
            if(b <= 0) return 0.0;
            if(memo.count(a) && memo[a].count(b)) return memo[a][b];
    
            double prob = 0.0;
            prob += 0.25 * helper(a - 100, b, memo);
            prob += 0.25 * helper(a - 75, b - 25, memo);
            prob += 0.25 * helper(a - 50, b - 50, memo);
            prob += 0.25 * helper(a - 25, b - 75, memo);
    
            memo[a][b] = prob;
            return prob;
        }
    };