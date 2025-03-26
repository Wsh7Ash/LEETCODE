#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build adjacency list with priority queue for lexicographical order
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        
        // Construct the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        
        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        
        // Reverse to get correct order
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
    
private:
    void dfs(string airport, 
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, 
             vector<string>& itinerary) {
        // While there are destinations from current airport
        while (!graph[airport].empty()) {
            string nextAirport = graph[airport].top();
            graph[airport].pop();
            dfs(nextAirport, graph, itinerary);
        }
        // Add current airport to itinerary
        itinerary.push_back(airport);
    }
};

// Test code
#include <iostream>
void printItinerary(const vector<string>& itinerary) {
    for (int i = 0; i < itinerary.size(); i++) {
        cout << itinerary[i];
        if (i < itinerary.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<string>> tickets1 = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    vector<string> result1 = solution.findItinerary(tickets1);
    printItinerary(result1);  // JFK -> MUC -> LHR -> SFO -> SJC
    
    // Test case 2
    vector<vector<string>> tickets2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> result2 = solution.findItinerary(tickets2);
    printItinerary(result2);  // JFK -> ATL -> JFK -> SFO -> ATL -> SFO
    
    return 0;
}
How it works:

Graph Construction:
Use an unordered_map to store the graph
For each airport (key), maintain a min priority queue of destinations
Priority queue ensures lexicographically smallest destination is chosen first
Hierholzer's Algorithm:
Use DFS to find Eulerian path
Start from "JFK"
For each airport:
Process all destinations in lexicographical order
Add current airport to itinerary after visiting all its destinations
Reverse the result to get correct order
Key Features:
Always starts at "JFK"
Uses all tickets exactly once
Returns lexicographically smallest valid itinerary
Handles cycles in the path
Example Walkthrough for [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]:
Graph: JFK→[ATL,SFO], SFO→[ATL], ATL→[JFK,SFO]
DFS path: JFK→ATL→JFK→SFO→ATL→SFO
Reverse: [JFK,ATL,JFK,SFO,ATL,SFO]
Complexity:

Time Complexity: O(E log E) where E is number of tickets
Building graph: O(E log E) due to priority queue
DFS traversal: O(E)
Space Complexity: O(E) for graph and recursion stack
The solution satisfies all constraints:

Works for 1 to 300 tickets
Handles 3-letter airport codes
Uses uppercase English letters
Starts from JFK
Uses all tickets
Returns lexicographically smallest itinerary
For the examples:

[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]] → ["JFK","MUC","LHR","SFO","SJC"]
[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]] → ["JFK","ATL","JFK","SFO","ATL","SFO"]