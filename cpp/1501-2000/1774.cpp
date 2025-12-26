class Solution {
    public:
        int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
            int res = baseCosts[0];
            
            for(int base : baseCosts){
                vector<bool> possible(20001, false);
                possible[base] = true;
                for(int topping : toppingCosts){
                    vector<bool> newPossible = possible;
                    for(int cost = 0; cost <= 20000; cost++){
                        if(possible[cost]){
                            if(cost + topping <= 20000){
                                newPossible[cost + topping] = true;
                            }
                            if(cost + topping * 2 <= 20000){
                                newPossible[cost + topping * 2] = true;
                            }
                        }
                    }
                    possible = newPossible;
                }
    
                for(int cost = 0; cost <= 20000; cost++){
                    if(possible[cost]){
                        if(abs(cost - target) < abs(res - target) ||
                            (abs(cost - target) == abs(res - target) && 
                            cost < target)){
                                res = cost;
                        }
                    }
                }
            }
            return res;
        }
    };