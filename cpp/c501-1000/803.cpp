
class DSU{
    public:
        vector<int> p;
        vector<int> s;
    
        DSU(int n) : p(n), s(n, 1){
            for(int i = 0; i < n; i++){
                p[i] = i;
            }
        }
    
        int find(int x){
            if(p[x] != x){
                p[x] = find(p[x]);
            }
            return p[x];
        }
        void unite(int x, int y){
            int fx = find(x);
            int fy = find(y);
            if(fx != fy){
                if(s[fx] < s[fy]){
                    swap(fx, fy);
                }
                p[fy] = fx;
                s[fx] += s[fy]; 
            }
        }
        int getSize(int x){
            return s[find(x)];
        }
    };   
    
    class Solution {
    public:
        vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<int>> tempGrid = grid;
    
        for(const auto& hit : hits){
            int x = hit[0], y = hit[1];
            if(tempGrid[x][y] == 1) tempGrid[x][y] = 0;
        }   
    
        DSU dsu(m * n + 1);
        int top = m * n;
    
        for(int j = 0; j < n;j++){
            if(tempGrid[0][j] == 1){
                dsu.unite(j, top);
            }
        }
    
        for(int i = 1; i <  m; i++){
            for(int j = 0; j < n; j++){
                if(tempGrid[i][j] == 1){
                    if(tempGrid[i-1][j] == 1){
                        dsu.unite(i*n+j, (i-1)*n+j);
                    }
                    if(j > 0 && tempGrid[i][j-1] == 1){
                        dsu.unite(i*n+j, i*n+j-1);
                    }
                }
            }
        }
        vector<int>  res(hits.size(), 0);
        vector<pair<int, int>> dirs = {{-1, 0}, {1,0}, {0, -1}, {0,1}};
    
        for(int k = hits.size() - 1; k >= 0; k--){
            int x = hits[k][0], y = hits[k][1];
            if(grid[x][y] == 0) continue;
            int ps = dsu.getSize(top);
            tempGrid[x][y] = 1;
            if(x == 0)dsu.unite(y, top);
    
            for(const auto& dir : dirs){
                int nx = x + dir.first;
                int ny = y + dir.second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && tempGrid[nx][ny] == 1){
                    dsu.unite(x*n+y, nx*n+ny);
                }
            }
            int newSize = dsu.getSize(top);
            res[k] = max(0, newSize - ps - 1);
        }
        return res;
        }
         
    };