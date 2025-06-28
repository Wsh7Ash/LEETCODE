class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            string target = "123450";
            string start;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    start += to_string(board[i][j]);
                }
            }
            if(start == target) return 0;
    
            unordered_set<string> visited;
            queue<pair<string, int>> q;
            q.push({start, 0});
            visited.insert(start);
    
            vector<vector<int>> dirs = {{1,3}, {0,2,4}, {1,5}, {0, 4}, {1,3,5}, {2, 4}};
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                string state = cur.first;
                int moves = cur.second;
    
                int zeropos = state.find('0');
                for(int newpos : dirs[zeropos]){
                    string newstate = state;
                    swap(newstate[zeropos], newstate[newpos]);
                    if(newstate == target){
                        return moves + 1;
                    }
                    if(visited.find(newstate) == visited.end()){
                        visited.insert(newstate);
                        q.push({newstate, moves+ 1});
                    
                    }
                }
            }
            return -1;
        }
    };