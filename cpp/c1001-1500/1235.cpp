class Solution {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n =  startTime.size();
    
            vector<vector<int>> jobs;
            for(int i = 0; i < n; i++){
                jobs.push_back({endTime[i], startTime[i], profit[i]});
            }
    
            sort(jobs.begin(), jobs.end());
    
            vector<int> endTimes;
            for(auto& job : jobs){
                endTimes.push_back(job[0]);
            }
    
            vector<int> dp(n + 1, 0);
    
            for(int i = 1; i <= n; i++){
                int end = jobs[i-1][0];
                int start = jobs[i-1][1];
                int prof = jobs[i-1][2];
    
                int pos = upper_bound(endTimes.begin(), endTimes.begin() + i - 1, start) - endTimes.begin();
    
                dp[i] = max(dp[i-1], prof + dp[pos]);
            }
    
            return dp[n];
        }
    };