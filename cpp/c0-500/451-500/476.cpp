class Solution {
    public:
        int findComplement(int num) {
            unsigned mask = ~0;
            while(num & mask){
                mask <<= 1;
            }
    
            mask = ~mask;
    
            return num ^ mask;
        }
    };