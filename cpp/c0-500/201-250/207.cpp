#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);  // 0 = not visited, 1 = visiting, 2 = visited
        
        // Build the graph
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        // DFS to detect cycle
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && !dfs(i, graph, visited)) {
                return false;  // Cycle detected
            }
        }
        
        return true;  // No cycle detected
    }
    
private:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[course] == 1) return false;  // Cycle detected
        if (visited[course] == 2) return true;   // Already processed
        
        visited[course] = 1;  // Mark as visiting
        
        // Visit all neighbors
        for (int neighbor : graph[course]) {
            if (!dfs(neighbor, graph, visited)) {
                return false;
            }
        }
        
        visited[course] = 2;  // Mark as fully visited
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << (solution.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;  // true
    
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << (solution.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;  // false
    
    return 0;
}
