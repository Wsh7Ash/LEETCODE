class Solution {
    public:
        int findLengthOfShortestSubarray(vector<int>& arr) {
            int n = arr.size();
            int r = n - 1;
            while(r > 0 && arr[r - 1] <= arr[r]){
                r--;
            }
            int res = r;
            for(int l = 0; l < n; l++){
                if(l > 0 && arr[l] < arr[l - 1]){
                    break;
                }
                while(r < n && (r <= l || arr[r] < arr[l])){
                    r++;
                }
                res = min(res, r - l - 1);
            }
            return res;
        }
    };