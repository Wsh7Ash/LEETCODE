class Solution {
    public:
        int countBalls(int lowLimit, int highLimit) {
            map<int, int> boxCount;
            for(int i = lowLimit; i <= highLimit; i++){
                int boxNumber = getDigitSum(i);
                boxCount[boxNumber]++;
            }
    
            int maxBalls = 0;
            for(const auto& pair : boxCount){
                maxBalls = max(maxBalls, pair.second);
            }
            return maxBalls;
        }
    
        int getDigitSum(int num){
            int sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    };