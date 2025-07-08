class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            unordered_set<int> visited;
            queue<int> q;
    
            q.push(0);
            visited.insert(0);
    
            while(!q.empty()){
                int cur = q.front();
                q.pop();
    
                for(int key : rooms[cur]){
                    if(visited.find(key) == visited.end()){
                        visited.insert(key);
                        q.push(key);
                    }
                }
            }
            return visited.size() == n;
        }
    };