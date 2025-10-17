class Solution {
    public:
        int numWaterBottles(int numBottles, int numExchange) {
            int t = numBottles;
            int e = numBottles;
    
            while(e >= numExchange){
                int n = e / numExchange;
                t += n;
                e = e % numExchange + n;
            }
            return t;
        }
    };