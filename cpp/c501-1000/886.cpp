class Solution {
    public:
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
           vector<vector<int>> adj(n+1);
           for(const auto& d : dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
           } 
    
           vector<int> color(n+1, -1);
           queue<int> q;
    
           for(int i =1; i<=n; i++){
            if(color[i] == -1){
                color[i] = 0;
                q.push(i);
    
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    
                    for(int v : adj[u]){
                        if(color[v] == -1){
                            color[v] = color[u] ^ 1;
                            q.push(v);
                        }else if(color[v] == color[u]){
                            return false;
                        }
                    }
                }
            }
           }
           return true;
        }
    };