class Solution {
    public:
        int bfs(vector<vector<int>>& forest, int start_x, int start_y, int end_x, int end_y){
            if(start_x == end_x && start_y == end_y) return 0;
    
            int m = forest.size();
            int n= forest[0].size();
            vector<vector<int>> visited(m, vector<int>(n, 0));
            queue<pair<int, int>> q;
            q.push({start_x, start_y});
            visited[start_x][start_y];
            int steps = 0;
            vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
    
            while(!q.empty()){
                int size = q.size();
                steps++;
                for(int i = 0; i < size; i++){
                    auto cur = q.front();
                    q.pop();
                    for(auto& dir : dirs){
                        int x = cur.first + dir[0];
                        int y = cur.second + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && !visited[x][y]){
                            if(x == end_x && y == end_y){
                                return steps;
                            }
                            visited[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
            return -1;
        }
    
        int cutOffTree(vector<vector<int>>& forest) {
            if(forest.empty() || forest[0].empty()) return -1;
    
            vector<vector<int>> trees;
            for(int i = 0; i < forest.size(); i++){
                for(int j = 0; j < forest[0].size(); j++){
                    if(forest[i][j] > 1){
                        trees.push_back({forest[i][j],i,j});
                    }
                }
            }
            sort(trees.begin(), trees.end());
    
            int total_steps = 0;
            int start_x = 0;
            int start_y = 0;
    
            for(auto& tree : trees){
                int end_x = tree[1];
                int end_y = tree[2];
                int steps = bfs(forest, start_x, start_y, end_x, end_y);
                if(steps == -1) return -1;
                total_steps += steps;
                start_x = end_x;
                start_y = end_y;
                forest[start_x][start_y] = 1;
            }
            return total_steps;
        }
    };