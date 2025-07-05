class Solution {
    public:
        int racecar(int target) {
            queue<pair<int, pair<int, int>>> q;
            unordered_set<string> visited;
    
            q.push({0, {0, 1}});
            visited.insert("0,1");
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int steps = cur.first;
                int pos = cur.second.first;
                int speed = cur.second.second;
    
                if(pos == target) return steps;
    
    
                int new_pos = pos + speed;
                int new_speed = speed * 2;
                string key = to_string(new_pos) + "," + to_string(new_speed);
                if(abs(new_pos) < 2 * target && visited.find(key) == visited.end()){
                    visited.insert(key);
                    q.push({steps + 1, {new_pos, new_speed}});
                }
                new_speed = speed > 0 ? -1 : 1;
                key = to_string(pos) + "," + to_string(new_speed);
                if(visited.find(key) == visited.end()){
                    visited.insert(key);
                    q.push({steps + 1, {pos, new_speed}});
                }
            }
            return -1;
        }
    };