class Solution {
    public:
        int longestMountain(vector<int>& arr) {
            int n = arr.size();
            if(n < 3) return 0;
            int ml = 0;
            int i = 1;
            while(i < n - 1){
                if(arr[i] > arr[i - 1] && arr[i] > arr[i+1]){
                    int l = i -1;
                    while(l > 0 && arr[l] > arr[l - 1]){
                        l--;
                    }
                    int r = i+1;
                    while(r < n -1 && arr[r] > arr[r+1]){
                        r++;
                    }
                    ml = max(ml, r - l + 1);
                    i = r;
                }else{
                    i++;
                }
            }
            return ml;
        }
    };