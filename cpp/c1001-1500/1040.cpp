class Solution {
    public:
        vector<int> numMovesStonesII(vector<int>& stones) {
            sort(stones.begin(), stones.end());
            int n = stones.size();
            int max_moves = max(stones[n-1]- stones[1] - (n-2), stones[n-2]- stones[0] - (n-2));
            int min_moves = n;
    
            for(int i = 0, j = 0; j < n; j++){
                while(stones[j] - stones[i] + 1 > n){
                    i++;
                }
    
                int cur_stones = j - i + 1;
                if(cur_stones == n - 1 && stones[j] - stones[i] + 1 == n - 1){
                    min_moves = min(min_moves, 2);
                }else{
                    min_moves = min(min_moves, n - cur_stones);
                }
            }
            return {min_moves, max_moves};
        }
    };