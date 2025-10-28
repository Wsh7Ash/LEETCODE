class Solution {
    public:
        int minimumDeviation(vector<int>& nums) {
            set<int> s;
            for(int num : nums){
                if(num % 2 == 1){
                    s.insert(num * 2);
                }else{
                    s.insert(num);
                }
            }
            int minDev = INT_MAX;
            while(true){
                int curMax = *s.rbegin();
                int curMin = *s.begin();
                minDev = min(minDev, curMax - curMin);
                if(curMax % 2 == 0){
                    s.erase(curMax);
                    s.insert(curMax / 2);
                }else{
                    break;
                }
            }
            return minDev;
        }
    };