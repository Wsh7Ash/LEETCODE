class Solution {
    public:
        double trimMean(vector<int>& arr) {
            sort(arr.begin(), arr.end());
            int n = arr.size();
            int removeCount = n * 0.05;
            double sum = 0;
            int count = 0;
    
            for(int i = removeCount; i < n - removeCount; i++){
                sum += arr[i];
                count++;
            }
            return sum / count;
        }
    };