class Solution {
    public:
        int findKthNumber(int m, int n, int k) {
            int l = 1, r = m * n;
            while(l < r){
                int mid = l + (r - l) / 2;
                int count   = 0;
                for(int j = 1; j <= m;j++){
                    count += min(mid / j, n);
                } 
                if(count < k){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            return l;
        }
    };