class Solution {
    public:
        int maxSatisfaction(vector<int>& satisfaction) {
            sort(satisfaction.begin(), satisfaction.end());
            int n = satisfaction.size();
    
            int suffixSum = 0;
            int maxSum = 0;
    
            for(int i = n - 1; i >= 0; i--){
                suffixSum += satisfaction[i];
                if(suffixSum < 0) break;
    
                maxSum += suffixSum;
            }
    
            return maxSum;
        }
    };