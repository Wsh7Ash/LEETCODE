class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;
    
            vector<int> lens(n, 1);
            vector<int> cts(n, 1);
            int maxlen = 1;
    
            for(int i = 1; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(nums[j] < nums[i]){
                        if(lens[j] + 1 > lens[i]){
                            lens[i] = lens[j] + 1;
                            cts[i] = cts[j];
                        }else if(lens[j] + 1 == lens[i]){
                            cts[i] += cts[j];
                        }
                    }
                }
                maxlen = max(maxlen, lens[i]);
            }
            int res = 0;
            for(int i = 0; i < n; i++){
                if(lens[i] == maxlen){
                    res += cts[i];
                }
            }
            return res;
        }
    };