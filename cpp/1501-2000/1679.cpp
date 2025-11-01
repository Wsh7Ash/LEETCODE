class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
            int ops = 0;
            for(int n : nums){
                int comp = k - n;
                if(freq[comp]  > 0){
                    ops++;
                    freq[comp]--;
                }else{
                    freq[n]++;
                }
            }
            return ops;
        }
    };