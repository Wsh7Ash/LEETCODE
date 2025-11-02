class Solution {
    public:
        int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
            int n = boxes.size();
            vector<int> trips(n + 1, 0);
            for(int i = 1; i < n; i++){
                trips[i] = trips[i-1] + (boxes[i][0] != boxes[i-1][0]);
            }
            vector<long long> weights(n + 1, 0);
            for(int i = 0; i < n; i++){
                weights[i + 1] = weights[i] + boxes[i][1];
            }
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
            deque<int> dq;
            dq.push_back(0);
            for(int i = 1; i <= n; i++){
                while(!dq.empty() && (i - dq.front() > maxBoxes || weights[i] - weights[dq.front()] > maxWeight)){
                    dq.pop_front();
                }
                int j = dq.front();
                dp[i] = dp[j] + trips[i - 1] - trips[j] + 2;
                while(!dq.empty() && dp[dq.back()] - trips[dq.back()] >= dp[i] - trips[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            return dp[n];
        }
    };