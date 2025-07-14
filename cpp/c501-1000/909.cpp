class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
            vector<int> flattened(n * n + 1);
            bool leftToRight = true;
            int index = 1;
    
            for(int i = n- 1; i >= 0; i--){
                if(leftToRight){
                    for(int j = 0; j < n; j++){
                        flattened[index++] = board[i][j];
                    }
                }else{
                    for(int j = n - 1; j >= 0; --j){
                        flattened[index++] = board[i][j];
                    }
                }
                leftToRight = !leftToRight;
            }
    
            queue<pair<int, int>> q;
            vector<bool> visited(n * n + 1, false);
            q.push({1, 0});
            visited[1] = true;
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int sqr = cur.first;
                int moves = cur.second;
    
                if(sqr == n * n) return moves;
    
                for(int i = 1; i <= 6; i++){
                    int next_sqr = sqr + i;
                    if(next_sqr > n * n){
                        continue;
                    }
                    if(flattened[next_sqr] != -1){
                        next_sqr = flattened[next_sqr];
                    }
                    if(!visited[next_sqr]){
                        visited[next_sqr] = true;
                        q.push({next_sqr, moves + 1});
                    }
                }
            }
            return -1;
        }
    };