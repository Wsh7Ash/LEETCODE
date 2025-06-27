class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
           int n = arr.size();
           vector<int> minR(n, INT_MAX);
    
           minR[n-1] = arr[n-1];
           for(int i = n-2; i >= 0; i--){
            minR[i] = min(arr[i], minR[i+1]);
           } 
           int maxL = INT_MIN;
           int chs = 0;
           for(int i = 0; i < n; i++){
            maxL = max(maxL, arr[i]);
            if(i == n - 1 || maxL <= minR[i+1]){
                chs++;
            }
           }
           return chs;
        }
    };