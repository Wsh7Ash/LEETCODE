class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            unordered_map<int, int> balanceMap;
            balanceMap[0] = -1;
            int maxLen = 0;
            int balance = 0;
    
            for(int i = 0; i < nums.size(); i++){
                balance += (nums[i] == 1) ? 1 : -1;
                if(balanceMap.find(balance) != balanceMap.end()){
                    maxLen = max(maxLen, i - balanceMap[balance]);
                }else{
                    balanceMap[balance] = i;
                }
            }
            return maxLen;
        }
    };