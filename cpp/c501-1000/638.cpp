class Solution {
    public:
        int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int>& memo){
            if(memo.find(needs) != memo.end()){
                return memo[needs];
            }
            int n = price.size();
            int minCost = 0;
            for(int i = 0; i < n; i++){
                minCost += needs[i] * price[i];
            }
            for(auto& offer : special){
                vector<int> newNeeds(needs.begin(), needs.end());
                bool valid = true;
                for(int i = 0; i < n; i++){
                    newNeeds[i] -= offer[i];
                    if(newNeeds[i] < 0){
                        valid = false;
                        break;
                    } 
                }
                if(valid){
                    int offerCost = offer[n] + dfs(price, special, newNeeds, memo);
                    minCost = min(minCost, offerCost);
                }
            }
            memo[needs] = minCost;
            return minCost;
        }
        int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
            map<vector<int>, int> memo;
            return dfs(price, special, needs, memo);
        }
    };