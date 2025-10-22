class Solution {
    public:
        int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
            int waiting = 0;
            int boarded = 0;
            int maxProfit = INT_MIN;
            int bestRotation = -1;
            int rotation = 0;
            int n = customers.size();
    
            int i = 0;
            while(i < n || waiting > 0){
                rotation++;
                if(i < n){
                    waiting += customers[i];
                    i++;
                }
                int board = min(4, waiting);
                boarded += board;
                waiting -= board;
    
                int profit = boarded * boardingCost - rotation * runningCost;
                if(profit > maxProfit){
                    maxProfit = profit;
                    bestRotation = rotation;
                }
            }
            return maxProfit > 0 ? bestRotation : -1;
        }
    };