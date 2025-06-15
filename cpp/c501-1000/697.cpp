class Solution {
    public:
        int findShortestSubArray(vector<int>& nums) {
            unordered_map<int, int> count, first_occurrence, last_occurrence;
            int max_freq = 0;
    
            for(int i = 0; i < nums.size(); i++){
                int num = nums[i];
                if(first_occurrence.find(num) == first_occurrence.end()){
                    first_occurrence[num] = i;
                }
                last_occurrence[num] = i;
                count[num]++;
                if(count[num] > max_freq){
                    max_freq = count[num];
                }
            }
            int min_len = nums.size();
            for(const auto& pair : count){
                if(pair.second == max_freq){
                    int length = last_occurrence[pair.first] - first_occurrence[pair.first] + 1;
                    if(length < min_len){
                        min_len = length;
                    }
                }
            }
            return min_len;
        }
    };