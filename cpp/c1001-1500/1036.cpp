class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty()) return true;

        unordered_set<long long> blocked_set;
        for(const auto& cell : blocked){
            blocked_set.insert((long long)cell[0] * 1000000 + cell[1]);
        }
        return bfs(source, target, blocked_set) && bfs(target, source, blocked_set);
    }

private:
    bool bfs(const vector<int>& start, const vector<int>& end, const unordered_set<long long>& blocked_set){
        const  long long max_area = 200 * 199 / 2;

        unordered_set<long long> visited;
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited.insert((long long)start[0] * 1000000 + start[1]);

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1, 0}};

        while(!q.empty() && visited.size() <= max_area){
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            if(x == end[0] && y == end[1]) return true;

            for(const auto& dir : dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                long long key = (long long)nx * 1000000 + ny;

                if(nx >= 0 && nx < 1000000 && ny >= 0 && ny < 1000000 && blocked_set.find(key) == blocked_set.end() && visited.find(key) == visited.end()){
                    visited.insert(key);
                    q.push({nx, ny});
                }
            }
        }
        return visited.size() > max_area;
    }
};