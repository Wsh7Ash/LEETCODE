class Solution {
    public:
        int minKBitFlips(vector<int>& nums, int k) {
            int n = nums.size();
            queue<int> fq;
            int res = 0;
    
            for(int i = 0; i < n; i++){
                while(!fq.empty() && fq.front() + k <= i){
                    fq.pop();
                }
                int cur = nums[i] ^ (fq.size() % 2);
                if(cur == 0){
                    if(i + k > n) return -1;
                    res++;
                    fq.push(i);
                }
            }
            return res;
        }
    };