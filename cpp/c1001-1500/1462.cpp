class Solution {
    public:
        vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
            
            vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
    
            for(const auto& pre : prerequisites){
                graph[pre[0]][pre[1]] = true;
            }
    
            for(int k = 0; k < numCourses; k++){
                for(int i = 0; i < numCourses; i++){
                    for(int j = 0; j < numCourses; j++){
                        if(graph[i][k] && graph[k][j]){
                            graph[i][j] = true;
                        }
                    }
                }
            }
    
            vector<bool> res;
            for(const auto& query : queries){
                res.push_back(graph[query[0]][query[1]]);
            }
            return res;
        }
    };