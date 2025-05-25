class Solution {
    public:
        bool isPossible(vector<int>& nums) {
            unordered_map<int, int> freq;
            unordered_map<int, int> append;
            for(int num :  nums){
                freq[num]++;
            }
            for(int num : nums){
                if(freq[num] == 0) continue;
                if(append[num] > 0){
                    append[num]--;
                    append[num + 1]++;
                    freq[num]--;
                }else if(freq[num+1] > 0 && freq[num+2] > 0){
                    freq[num]--;
                    freq[num + 1]--;
                    freq[num + 2]--;
                    append[num + 3]++;
                }else{
                    return false;
                }
            }
            return true;
        }
    };