class Solution {
    public:
        int minCost(int n, vector<int>& cuts) {
            cuts.push_back(0);
            cuts.push_back(n);
            sort(cuts.begin(), cuts.end());
            int m = cuts.size();
            vector<vector<int>> memo(m , vector<int>(m, -1));
            return dfs(cuts, 0, m - 1, memo);
        }
    
    private:
        int dfs(vector<int>& cuts, int i, int j, vector<vector<int>>& memo){
            if(j - i <= 1) return 0;
            if(memo[i][j] != -1) return memo[i][j];
    
            int res = INT_MAX;
    
            for(int k = i + 1; k < j; k++){
                int cost = dfs(cuts, i, k, memo) + dfs(cuts, k, j, memo) + (cuts[j] - cuts[i]);
                res = min(res, cost);
            }
    
            return memo[i][j] = res;
        }
    };