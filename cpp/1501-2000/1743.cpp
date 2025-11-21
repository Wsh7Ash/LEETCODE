class Solution {
    public:
        vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
            map<int, vector<int>> graph;
            for(const auto& pair : adjacentPairs){
                graph[pair[0]].push_back(pair[1]);
                graph[pair[1]].push_back(pair[0]);
            }
            int start = 0;
            for(const auto& entry :  graph){
                if(entry.second.size() == 1){
                    start = entry.first;
                    break;
                }
            }
            vector<int> res;
            set<int> visited;
            int cur = start;
    
            while(res.size() < graph.size()){
                res.push_back(cur);
                visited.insert(cur);
                for(int nei : graph[cur]){
                    if(visited.find(nei) == visited.end()){
                        cur = nei;
                        break;
                    }
                }
            }
            return res;
        }   
    };