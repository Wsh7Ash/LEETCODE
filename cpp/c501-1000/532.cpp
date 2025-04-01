class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
            for(int num : nums){
                freq[num]++;
            }
            int count = 0;
            for(auto& [num, cnt] : freq){
                if(k == 0){
                    if(cnt >= 2){
                        count++;
                    }
                }else{
                    if(freq.find(num + k) != freq.end()){
                        count++;
                    }
                }
            }
            return count;
        }
    };