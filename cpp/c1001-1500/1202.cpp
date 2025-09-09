class Solution {
    public:
        string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
            int n = s.size();
            vector<vector<int>> graph(n);
    
            for(const auto& pair : pairs){
                graph[pair[0]].push_back(pair[1]);
                graph[pair[1]].push_back(pair[0]);
            }
    
            vector<bool> visited(n, false);
    
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    vector<int> indices;
                    vector<char> chars;
    
                    function<void(int)> dfs = [&](int node){
                        visited[node] = true;
                        indices.push_back(node);
                        chars.push_back(s[node]);
    
                        for(int nei : graph[node]){
                            if(!visited[nei]){
                                dfs(nei);
                            }
                        }
                    };
    
                    dfs(i);
                    sort(indices.begin(), indices.end());
                    sort(chars.begin(), chars.end());
    
                    for(int j = 0; j < indices.size(); j++){
                        s[indices[j]] = chars[j];
                    }
                }
            }
            return s;
        }
    };