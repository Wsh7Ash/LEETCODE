class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
         int last_day = days.back();
        vector<int> dp(last_day + 1, INT_MAX);
        dp[0] = 0;
        int day_index = 0;
    
        for(int i = 1; i <= last_day; i++){
            if(day_index < days.size() && i == days[day_index]){
                int c1 = dp[i-1] + costs[0];
                int c7 = (i - 7 >= 0) ? dp[i-7] + costs[1] : costs[1];
                int c30 = (i - 30 >= 0) ? dp[i-30] + costs[2] : costs[2];
                dp[i] = min({c1,c7,c30});
                day_index++;
            }else{
                dp[i] = dp[i-1];
            }
        } 
        return dp[last_day];   
        }
    };