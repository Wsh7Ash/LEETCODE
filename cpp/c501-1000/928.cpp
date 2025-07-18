class Solution {
    public:
        int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
            int n = graph.size();
            sort(initial.begin(), initial.end());
            int min_infected = n + 1;
            int res = initial[0];
    
            for(int remove_node : initial){
                unordered_set<int> infected(initial.begin(), initial.end());
                infected.erase(remove_node);
                queue<int> q;
                for(int node : infected){
                    q.push(node);
                }
    
                vector<vector<int>> temp_graph = graph;
                for(int i = 0; i < n; i++){
                    temp_graph[remove_node][i] = 0;
                    temp_graph[i][remove_node] = 0;
                }
    
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(int nei = 0; nei < n; nei++){
                        if(temp_graph[cur][nei] == 1 && infected.find(nei) == infected.end()){
                            infected.insert(nei);
                            q.push(nei);
                        }
                    }
                }
                if(infected.size() < min_infected){
                    min_infected = infected.size();
                    res = remove_node;
                }else if(infected.size() == min_infected && remove_node < res){
                     res = remove_node;
                }
            }
            return res;
        }
    };