class Solution {
    public:
        int findBestValue(vector<int>& arr, int target) {
            sort(arr.begin(), arr.end());
    
            int n = arr.size();
    
            vector<long long> prefixSum(n + 1, 0);
            for(int i = 0; i < n; i++){
                prefixSum[i + 1] = prefixSum[i] + arr[i];
            }
    
            int left = 0, right = arr[n - 1];
            int bestValue = 0;
            int minDiff = INT_MAX;
    
            long long sumAll = prefixSum[n];
            if(abs(sumAll - target) <  minDiff){
                minDiff = abs(sumAll - target);
                bestValue = arr[n - 1];
            }
    
            while(left <= right){
                int mid = left + (right - left) /2;
                long long sum = calcSum(arr, prefixSum, mid);
                int diff = abs(sum - target);
    
                if(diff < minDiff){
                    minDiff = diff;
                    bestValue = mid;
                }
                else if(diff == minDiff){
                    bestValue = min(bestValue, mid);
                }
    
                if(sum < target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return bestValue;
        }
    
    private:
        long long calcSum(vector<int>& arr,vector<long long>& prefixSum, int value){
            int pos = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            long long sum = prefixSum[pos] + (long long)(arr.size() - pos) * value;
            return sum;
        }
    };