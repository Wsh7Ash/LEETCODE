class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int c = 0;
            int h = -prices[0];
            for(int i = 1; i < prices.size(); i++){
                c = max(c, h + prices[i] - fee);
                h = max(h, c - prices[i]);
            }
            return c;
        }
    };