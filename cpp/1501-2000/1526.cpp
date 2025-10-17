class Solution {
    public:
        int minNumberOperations(vector<int>& target) {
            int ops = 0;
            int prev = 0;
    
            for(int num : target){
                if(num > prev){
                    ops += num - prev;
                }
                prev = num;
            }
            return ops;
        }
    };