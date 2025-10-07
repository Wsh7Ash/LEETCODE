class Solution {
    public:
        int numOfSubarrays(vector<int>& arr, int k, int threshold) {
            int n = arr.size();
            int count = 0;
    
            int sumThreshold = k * threshold;
    
            int windowSum = 0;
    
            for(int i = 0; i < k; i++){
                windowSum += arr[i];
            }
    
            if(windowSum >= sumThreshold){
                count++;
            }
    
            for(int i = k; i < n; i++){
                windowSum = windowSum - arr[i- k] + arr[i];
                if(windowSum >= sumThreshold){
                    count++;
                }
            }
            return count;
        }
    };