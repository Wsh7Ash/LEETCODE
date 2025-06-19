class Solution {
    public:
        int smallestDistancePair(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int l = 0;
            int r = nums.back() - nums.front();
    
            while(l < r){
                int m = l + (r - l) / 2;
                int c = 0;
                int i = 0;
                for(int j = 0; j < n; j++){
                    while(nums[j] - nums[i] > m){
                        i++;
                    }
                    c += j - i;
                }
                if(c < k){
                    l = m + 1;
                }else{
                    r = m;
                }
            }
            return l;
        }
    };