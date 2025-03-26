class Solution {
    public:
        int hammingDistance(int x, int y) {
            int xor_re = x ^ y;
            int distance = 0;
            while(xor_re){
                distance += xor_re & 1;
                xor_re >>= 1;
            }
            return distance;
        }
    };