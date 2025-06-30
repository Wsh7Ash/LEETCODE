class Solution {
    public:
        int preimageSizeFZF(int k) {
            return (int)(binarySearch(k+1) - binarySearch(k));
        }
    
        long binarySearch(int k){
            long l = 0, r = 5L * ( k+1);
            while(l <= r){
                long m = l + (r-l) / 2;
                long zs = countZeros(m);
                if(zs < k) l = m + 1;
                else r = m - 1;
            }
            return l;
        }
    
        long countZeros(long x){
            long c = 0;
            while(x > 0){
                x /= 5;
                c += x;
            }
            return c;
        }
        
    };