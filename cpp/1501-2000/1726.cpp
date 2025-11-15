class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int n = nums.size();
            map<long long, int> productCount;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    long long product = (long long)nums[i] * nums[j];
                    productCount[product]++;
                }
            }
            int res = 0;
            for(const auto& entry : productCount){
                int count = entry.second;
                if(count >= 2){
                    res += count * (count - 1) / 2 * 8;
                }
            }
            return res;
        }
    };