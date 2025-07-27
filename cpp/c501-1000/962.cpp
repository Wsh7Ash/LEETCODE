class Solution {
    public:
        int maxWidthRamp(vector<int>& nums) {
            int n = nums.size();
            stack<int> s;
            for(int i = 0; i < n; i++){
                if(s.empty() || nums[i] < nums[s.top()]){
                    s.push(i);
                }
            }
    
            int max_width = 0;
            for(int j = n - 1; j >= 0; j--){
                while(!s.empty() && nums[j] >= nums[s.top()]){
                    max_width = max(max_width, j - s.top());
                    s.pop();
                }
            }
            return  max_width;
        }
    };