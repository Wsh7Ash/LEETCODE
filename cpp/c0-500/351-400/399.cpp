class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, 
                                  vector<double>& values, 
                                  vector<vector<string>>& queries) {
            // Build graph
            unordered_map<string, unordered_map<string, double>> graph;
            for (int i = 0; i < equations.size(); i++) {
                string& from = equations[i][0];
                string& to = equations[i][1];
                double val = values[i];
                
                // Add both directions
                graph[from][to] = val;
                graph[to][from] = 1.0 / val;
            }
            
            // Process queries
            vector<double> results;
            for (auto& query : queries) {
                string start = query[0];
                string end = query[1];
                
                // If either variable not in graph, result is -1
                if (graph.find(start) == graph.end() || 
                    graph.find(end) == graph.end()) {
                    results.push_back(-1.0);
                    continue;
                }
                
                // If same variable, result is 1
                if (start == end) {
                    results.push_back(1.0);
                    continue;
                }
                
                // DFS to find path
                unordered_set<string> visited;
                double result = dfs(graph, start, end, visited);
                results.push_back(result);
            }
            
            return results;
        }
        
    private:
        double dfs(unordered_map<string, unordered_map<string, double>>& graph,
                  string& start, string& end, unordered_set<string>& visited) {
            // Mark current node as visited
            visited.insert(start);
            
            // Check all neighbors
            for (auto& [next, value] : graph[start]) {
                if (next == end) {
                    return value;  // Found direct path
                }
                
                if (visited.find(next) == visited.end()) {
                    double subResult = dfs(graph, next, end, visited);
                    if (subResult != -1.0) {
                        return value * subResult;  // Path found through this neighbor
                    }
                }
            }
            
            return -1.0;  // No path found
        }
    };
    How this solution works:
    
    Approach:
    Build a directed weighted graph where edges represent division relationships
    Use DFS to find paths between query variables
    Multiply weights along paths to get result
    Graph Construction:
    For each equation A/B = v:
    Add edge A→B with weight v
    Add edge B→A with weight 1/v
    Uses nested unordered_map for adjacency list
    Query Processing:
    For each query C/D:
    Handle special cases first (undefined variables, same variable)
    Use DFS to find path from C to D
    Return -1 if no path found
    DFS Implementation:
    Explores neighbors recursively
    Uses visited set to avoid cycles
    Multiplies weights along path
    Returns -1 if no path exists
    Example Walkthrough (equations=[["a","b"],["b","c"]], values=[2.0,3.0]):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Graph:
    a → b: 2.0
    b → a: 0.5
    b → c: 3.0
    c → b: 0.333...
    
    Query "a"→"c":
    - a→b (2.0) → c (3.0) = 6.0
    Complexity:
    Time: O(Q * (V + E)) where Q is number of queries, V is vertices, E is edges
    Space: O(V + E) for graph + O(V) for recursion stack
    The solution handles all constraints:
    
    equations.length from 1 to 20
    variable lengths from 1 to 5
    values > 0.0 and ≤ 20.0
    queries.length from 1 to 20
    lowercase letters and digits
    Key features:
    
    Handles undefined variables (-1.0)
    Handles self-division (1.0)
    No division by zero (guaranteed by problem)
    Precise floating-point calculations
    For the example cases:
    
    Example 1: [6.0, 0.5, -1.0, 1.0, -1.0]
    Example 2: [3.75, 0.4, 5.0, 0.2]
    Example 3: [0.5, 2.0, -1.0, -1.0]
    The graph-based DFS approach efficiently solves this problem by converting division relationships into a path-finding problem, making it both intuitive and effective.