class Solution {
    public:
        int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            vector<vector<int>> dirs = {{0,1}, {1,0},{0,-1}, {-1, 0}};
            int x = 0, y = 0;
            int dir = 0;
            unordered_set<string> obs;
            for(const auto& ob : obstacles){
                obs.insert(to_string(ob[0]) + "," + to_string(ob[1]));
            }
    
            int md = 0;
            for(int cmd : commands){
                if(cmd == -2) dir = (dir - 1 + 4) % 4;
                else if(cmd == -1) dir = (dir + 1) % 4;
                else{
                    for(int step = 0; step < cmd; step++){
                        int nx = x + dirs[dir][0];
                        int ny = y + dirs[dir][1];
                        string key = to_string(nx) + "," + to_string(ny);
                        if(obs.find(key) != obs.end()) break;
                        x = nx;
                        y = ny;
                        md = max(md, x*x + y * y);
                    }
                }
            }
            return md;
        }
    };