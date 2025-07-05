class Solution {
    public:
        int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
            vector<pair<int,int>> jobs;
            int n = difficulty.size();
            for(int i = 0; i < n; i++){
                jobs.emplace_back(difficulty[i], profit[i]);
            }
    
            sort(jobs.begin(), jobs.end());
            sort(worker.begin(), worker.end());
    
            vector<int> maxProfitUpTo(n);
            maxProfitUpTo[0] = jobs[0].second;
            for(int i = 1; i < n; i++){
                maxProfitUpTo[i] = max(maxProfitUpTo[i-1], jobs[i].second);
            }
    
            int totalProfit = 0;
            int jobIndex = 0;
            int curMaxProfit = 0;
    
            for(int ability : worker){
                while(jobIndex < n && jobs[jobIndex].first <= ability){
                    curMaxProfit = max(curMaxProfit, jobs[jobIndex].second);
                    jobIndex++;
                }
                if(jobIndex > 0){
                    totalProfit += curMaxProfit;
                }
            }
            return totalProfit;
        }
    };