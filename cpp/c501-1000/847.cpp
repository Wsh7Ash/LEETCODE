class Solution {
    public:
        int shortestPathLength(vector<vector<int>>& graph) {
            int n = graph.size();
            if(n == 1) return 0;
    
            queue<tuple<int, int, int>> q;
            unordered_set<int> visited;
    
            for(int i =0; i < n; i++){
                int mask = 1 << i;
                q.push({i, mask, 0});
                visited.insert((i << 16) | mask);
            }
    
            int all_visited = (1 << n) - 1;
    
            while(!q.empty()){
                auto [node, mask, len] = q.front();
                q.pop();
    
                if(mask == all_visited) return len;
    
                for(int nei : graph[node]){
                    int new_mask = mask | (1 << nei);
                    int key = (nei << 16) | new_mask;
                    if(visited.find(key) == visited.end()){
                        visited.insert(key);
                        q.push({nei, new_mask, len+1});
                    }
                }
            }
            return -1;
        }
    };