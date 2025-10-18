class Solution {
    public:
        char findKthBit(int n, int k) {
            int curN = n;
            bool flip = false;
            while(curN > 1){
                int len = (1 << curN) - 1;
                int mid = (len + 1) / 2;
                if(k == mid){
                    return flip ? '0' : '1';
                }
                else if(k > mid){
                    k = len - k + 1;
                    flip = !flip;
                }
                curN--;
            }
    
            return flip ? '1' : '0';
        }
    };