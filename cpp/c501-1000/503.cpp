class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n,  -1);
            stack<int> s;
    
            for(int i = 0; i < 2 * n; i++){
                int num  = nums[i % n];
                while(!s.empty() && nums[s.top()] < num){
                    res[s.top()] = num;
                    s.pop();
                }
                if(i < n){
                    s.push(i);
                }
            }
            return res;
        }
    };