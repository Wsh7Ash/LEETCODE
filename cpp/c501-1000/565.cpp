class Solution {
    public:
        int arrayNesting(vector<int>& nums) {
            int n = nums.size();
            vector<bool> visited(n , false);
            int max_len = 0;
    
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    int cur = i;
                    int count = 0;
                    while(!visited[cur]){
                        visited[cur] = true;
                        cur = nums[cur];
                        count++;
                    }
                    max_len = max(max_len, count);
                }
            }
            return max_len;
        }
    };