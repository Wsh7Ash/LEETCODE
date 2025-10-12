class Solution {
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            int n = candies.size();
            vector<bool> res(n);
    
            int maxCandies = 0;
            for(int candy : candies){
                if(candy > maxCandies){
                    maxCandies = candy;
                }
            }
    
            for(int i = 0; i < n; i++){
                res[i] = (candies[i] + extraCandies >= maxCandies);
            }
    
            return res;
        }
    };