class Solution {
    public:
        int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
            int n = nums.size();
            const int MOD = 1e9+7;
    
            vector<int> freq(n + 1, 0);
    
            for(auto& req : requests){
                freq[req[0]]++;
                if(req[1] + 1 < n){
                    freq[req[1] + 1]--;
                }
            }
            for(int i = 1; i < n; i++){
                freq[i] += freq[i - 1];
            }
    
            priority_queue<int> freqPQ, numPQ;
    
            for(int i = 0; i < n; i++){
                if(freq[i] > 0){
                    freqPQ.push(freq[i]);
                }
                numPQ.push(nums[i]);
            }
    
            long long total = 0;
            while(!freqPQ.empty() && !numPQ.empty()){
                total = (total + (long long)freqPQ.top() * numPQ.top()) % MOD;
                freqPQ.pop();
                numPQ.pop();
            }
            return total;
        }
    };