class Solution {
    private:
        const int MOD = 1e9+7;
        vector<vector<long long>> comb;
    
    public:
        int numOfWays(vector<int>& nums) {
            int n = nums.size();
            comb = vector<vector<long long>>(n+1, vector<long long>(n+1, 0));
            for(int i = 0; i <= n; i++){
                comb[i][0] = comb[i][i] = 1;
                for(int j = 1; j < i; j++){
                    comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
                }
            }
            return (dfs(nums) - 1 + MOD) % MOD;
        }
    
    private:
        long long dfs(vector<int>& nums){
            int n = nums.size();
            if(n <= 2) return 1;
            vector<int> l, r;
            int root = nums[0];
    
            for(int i = 1; i < n; i++){
                if(nums[i] < root){
                    l.push_back(nums[i]);
                }else{
                    r.push_back(nums[i]);
                }
            }
    
            long long lw = dfs(l);
            long long rw = dfs(r);
            long long il = comb[n-1][l.size()];
            return (il * lw % MOD) * rw % MOD;
        }
    };