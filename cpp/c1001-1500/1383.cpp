class Solution {
    public:
        int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
            const int MOD = 1e9 + 7;
    
            vector<pair<int, int>> engs;
            for(int i = 0; i < n; i++){
                engs.push_back({efficiency[i], speed[i]});
            }
    
            sort(engs.rbegin(), engs.rend());
    
            priority_queue<int, vector<int>, greater<int>> minHeap;
    
            long long sumSpeed = 0;
            long long maxPerf = 0;
    
            for(auto& [eff, spd] : engs){
                sumSpeed += spd;
                minHeap.push(spd);
    
                if(minHeap.size() > k){
                    sumSpeed -= minHeap.top();
                    minHeap.pop();
                }
    
                maxPerf = max(maxPerf, sumSpeed * eff);
            }
            
    
            return maxPerf % MOD;
        }
    };