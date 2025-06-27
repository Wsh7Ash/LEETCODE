class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
       int m = isInfected.size();
       if(m==0) return 0;
       int n = isInfected[0].size();
       int walls = 0;

       while(true){
        vector<unordered_set<int>> regions;
        vector<unordered_set<int>> frontiers;
        vector<int> perimeters;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isInfected[i][j] == 1 && !visited[i][j]){
                    queue<pair<int, int>> q;
                    unordered_set<int> region;
                    unordered_set<int> frontier;
                    int perimeter = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                    region.insert(i*n+j);

                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        int x = cur.first;
                        int y = cur.second;
                        for(int k = 0; k < 4; k++){
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                                if(isInfected[nx][ny] == 1 && !visited[nx][ny]){
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                    region.insert(nx*n+ny);
                                }else if(isInfected[nx][ny] == 0){
                                    frontier.insert(nx*n+ny);
                                    perimeter++;
                                }
                            }
                        }
                    }
                    regions.push_back(region);
                    frontiers.push_back(frontier);
                    perimeters.push_back(perimeter);
                }
            }
        }
        if(regions.empty()) break;

        int max_idx = 0;
        int max_frontier = frontiers[0].size();
        for(int i = 1; i < frontiers.size(); i++){
            if(frontiers[i].size() > max_frontier){
                max_frontier = frontiers[i].size();
                max_idx = i;
            }
        }

        walls += perimeters[max_idx];

        for(int i = 0; i < regions.size(); i++){
            if(i == max_idx){
                for(int cell : regions[i]){
                    int x = cell / n;
                    int y = cell % n;
                    isInfected[x][y] = -1;
                }
            }else{
                for(int cell : regions[i]){
                    int x = cell / n;
                    int y = cell % n;
                    for(int k = 0; k < 4; k++){
                        int nx = x + dirs[k][0];
                        int ny = y + dirs[k][1];
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n && isInfected[nx][ny] == 0){
                            isInfected[nx][ny] = 1;
                        }
                    }
                }
            }
        }
       } 
        return walls;
    }
    const vector<vector<int>> dirs = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
};