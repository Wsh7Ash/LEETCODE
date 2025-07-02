class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            if(source == target) return 0;
    
            unordered_map<int, vector<int>> stopToRoutes;
            for(int i = 0; i < routes.size(); i++){
                for(int stop : routes[i]){
                    stopToRoutes[stop].push_back(i);
                }
            }
    
            queue<int> q;
            unordered_set<int> visitedRoutes;
            unordered_set<int> visitedStops;
    
            for(int route : stopToRoutes[source]){
                q.push(route);
                visitedRoutes.insert(route);
            }
            visitedStops.insert(source);
    
            int buses = 1;
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    int curRoute = q.front();
                    q.pop();
                    for(int stop : routes[curRoute]){
                        if(stop == target){
                            return buses;
                        }
                        if(visitedStops.find(stop) == visitedStops.end()){
                            visitedStops.insert(stop);
                            for(int nextRoute : stopToRoutes[stop]){
                                if(visitedRoutes.find(nextRoute) == visitedRoutes.end()){
                                    visitedRoutes.insert(nextRoute);
                                    q.push(nextRoute);
                                }
                            }
                        }
                    }
                }
                buses++;
            }
            return -1;
        }
    };