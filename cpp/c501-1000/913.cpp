class Solution {
    public:
        int catMouseGame(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, 0)));
            vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));
            
            for (int m = 0; m < n; m++) {
                for (int c = 0; c < n; c++) {
                    degree[m][c][0] = graph[m].size();
                    degree[m][c][1] = graph[c].size();
                    for (int node : graph[c]) {
                        if (node == 0) {
                            degree[m][c][1]--;
                            break;
                        }
                    }
                }
            }
            
            queue<tuple<int, int, int, int>> q;
            
            for (int c = 0; c < n; c++) {
                for (int t = 0; t < 2; t++) {
                    color[0][c][t] = 1;
                    q.push({0, c, t, 1});
                    if (c > 0) {
                        color[c][c][t] = 2;
                        q.push({c, c, t, 2});
                    }
                }
            }
            
            while (!q.empty()) {
                auto [mouse, cat, turn, result] = q.front();
                q.pop();
                
                if (turn == 0) {
                    for (int prevCat : graph[cat]) {
                        if (prevCat == 0) continue;
                        if (color[mouse][prevCat][1] != 0) continue;
                        
                        if (result == 2) {
                            color[mouse][prevCat][1] = 2;
                            q.push({mouse, prevCat, 1, 2});
                        } else {
                            degree[mouse][prevCat][1]--;
                            if (degree[mouse][prevCat][1] == 0) {
                                color[mouse][prevCat][1] = 1;
                                q.push({mouse, prevCat, 1, 1});
                            }
                        }
                    }
                } else {
                    for (int prevMouse : graph[mouse]) {
                        if (color[prevMouse][cat][0] != 0) continue;
                        
                        if (result == 1) {
                            color[prevMouse][cat][0] = 1;
                            q.push({prevMouse, cat, 0, 1});
                        } else {
                            degree[prevMouse][cat][0]--;
                            if (degree[prevMouse][cat][0] == 0) {
                                color[prevMouse][cat][0] = 2;
                                q.push({prevMouse, cat, 0, 2});
                            }
                        }
                    }
                }
            }
            
            return color[1][2][0];
        }
    };