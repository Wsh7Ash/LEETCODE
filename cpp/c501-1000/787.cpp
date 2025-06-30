class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int, int>>> adj(n);
            for(const auto& flight : flights){
                adj[flight[0]].emplace_back(flight[1], flight[2]);
            } 
    
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
            pq.emplace(0, src, k + 1);
    
            vector<vector<int>> minCost(n, vector<int>(k+2, INT_MAX));
            minCost[src][k+1] = 0;
    
            while(!pq.empty()){
                auto [ cost, city, stops] = pq.top();
                pq.pop();
    
                if(city == dst) return cost;
                if(stops == 0) continue;
                for(const auto& [nextCity, price] : adj[city]){
                    int newCost = cost + price;
                    int newStops = stops - 1;
                    if(newCost < minCost[nextCity][newStops]){
                        minCost[nextCity][newStops] = newCost;
                        pq.emplace(newCost, nextCity, newStops);
                    }
                }
            }
            return -1;
        }
    };