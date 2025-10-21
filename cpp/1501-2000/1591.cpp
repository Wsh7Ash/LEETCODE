class Solution {
    public:
        bool isPrintable(vector<vector<int>>& targetGrid) {
            int m = targetGrid.size();
            int n = targetGrid[0].size();
    
            vector<int> top(61, m);
            vector<int> bottom(61, -1);
            vector<int> left(61, n);
            vector<int> right(61, -1);
            unordered_set<int> colors;
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    int c = targetGrid[i][j];
                    colors.insert(c);
                    top[c] = min(top[c], i);
                    bottom[c] = max(bottom[c], i);
                    left[c] = min(left[c], j);
                    right[c] = max(right[c], j);
                }
            }
    
            vector<vector<int>> graph(61);
            for(int c : colors){
                for(int i = top[c]; i <= bottom[c]; i++){
                    for(int j = left[c]; j <= right[c]; j++){
                        int other = targetGrid[i][j];
                        if(other != c){
                            graph[c].push_back(other);
                        }
                    }
                }
            }
    
            vector<int> state(61, 0);
    
            function<bool(int)> hasCycle = [&](int node){
                if(state[node] == 1) return true;
                if(state[node] == 2) return false;
                state[node] = 1;
                for(int nei : graph[node]){
                    if(hasCycle(nei)) return true;
                }
                state[node] = 2;
                return false;
            };
    
            for(int c : colors){
                if(state[c] == 0 && hasCycle(c)){
                    return false;
                }
            }
            return true;
        }
    };