class Solution {
    public:
        int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            vector<int> memo(n, -1);
            int maxTime = 0;
    
            for(int i = 0; i < n; i++){
                
                maxTime = max(maxTime, dfs(i, manager, informTime, memo));
                
            }
    
            return maxTime;
        }
    
    private:
        int dfs(int emp, vector<int>& manager, vector<int>& informTime, vector<int>& memo){
            if(memo[emp] != -1){
                return memo[emp];
            }
    
            if(manager[emp] == -1) memo[emp] = informTime[emp];
            else memo[emp] = informTime[emp] + dfs(manager[emp], manager, informTime, memo);
    
            return  memo[emp];
        }
    };