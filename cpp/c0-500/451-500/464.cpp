class Solution {
    public:
        unordered_map<int, bool> memo;
        bool canWin(int maxChoosable, int desiredTotal, int usedNumbers, int currentTotal){
            if(memo.find(usedNumbers) != memo.end()) return memo[usedNumbers];
    
            for(int i = 1; i <= maxChoosable; i++){
                if(!(usedNumbers & (1 << i))){
                    if(currentTotal + i >= desiredTotal){
                        memo[usedNumbers] = true;
                        return true;
                    }
    
                    if(!canWin(maxChoosable, desiredTotal, usedNumbers | (1 << i), currentTotal + i)){
                        memo[usedNumbers] = true;
                        return true;
                    }
                }
            }
            memo[usedNumbers] = false;
            return false;
        } 
        bool canIWin(int maxChoosableInteger, int desiredTotal) {
            int maxSum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
            if(maxSum <  desiredTotal) return false;
    
            if(desiredTotal <= 0) return true;
    
            memo.clear();
            return canWin(maxChoosableInteger, desiredTotal, 0, 0);
        }
    };