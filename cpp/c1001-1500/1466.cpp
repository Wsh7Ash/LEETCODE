class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            
            vector<vector<pair<int, int>>> graph(n);
    
            for(const auto& conn : connections){
                int from = conn[0];
                int to = conn[1];
                graph[from].push_back({to, true});
                graph[to].push_back({from, false});
            }
    
            int changes = 0;
            vector<bool> visited(n, false);
            queue<int> q;
    
            q.push(0);
            visited[0] = true;
    
            while(!q.empty()){
                int city = q.front();
                q.pop();
    
                for(const auto& [nei, isOriginal] : graph[city]){
                    if(!visited[nei]){
                        visited[nei] = true;
    
                        if(isOriginal) changes++;
    
                        q.push(nei);
                    }
                }
            }
            return changes;
        }
    };