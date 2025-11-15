class Solution {
    public:
        int res = INT_MAX;
        void backtrack(vector<int>& jobs, vector<int>& workers, int jobIndex, int curMax){
            if(curMax >= res) return;
            if(jobIndex == jobs.size()){
                res = min(res, curMax);
                return;
            }
            for(int i = 0; i < workers.size(); i++){
                if(i > 0 && workers[i] == workers[i - 1]){
                    continue;
                }
                workers[i] += jobs[jobIndex];
                backtrack(jobs, workers, jobIndex + 1, max(curMax, workers[i]));
                workers[i] -= jobs[jobIndex];
            }
        }
    
        int minimumTimeRequired(vector<int>& jobs, int k) {
            sort(jobs.begin(), jobs.end(), greater<int>());
            vector<int> workers(k, 0);
            backtrack(jobs, workers, 0, 0);
            return res;
        }
    };