class Solution {
    public:
        vector<int> numMovesStones(int a, int b, int c) {
            vector<int> stones = {a, b, c};
            sort(stones.begin(), stones.end());
            int x = stones[0];
            int y = stones[1];
            int z = stones[2];
    
            int min_moves, max_moves;
    
            if(z - x == 2){
                min_moves = 0;
                max_moves = 0;
            }
            else if(y - x == 1 || z - y == 1){
                min_moves = 1;
                max_moves = z- x - 2;
            }
            else if(y - x == 2 || z - y == 2){
                min_moves = 1;
                max_moves = z - x - 2;
            }
            else{
                min_moves = 2;
                max_moves = z - x - 2;
            }
            return {min_moves, max_moves};
        }
    };