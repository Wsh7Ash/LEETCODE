class Solution {
    public:
        bool isPossibleDivide(vector<int>& nums, int k) {
            if(nums.size() % k != 0) return false;
    
            map<int, int> count;
            for(int num : nums) count[num]++;
    
            while(!count.empty()){
                int start = count.begin()->first;
    
                for(int i = 0; i < k; i++){
                    int cur = start + i;
    
                    if(count[cur] == 0) return false;
    
                    count[cur]--;
    
                    if(count[cur] == 0) count.erase(cur);
                }
            }
            return true;
        }
    };