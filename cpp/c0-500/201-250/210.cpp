#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Step 1: Build the graph and calculate in-degrees
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        int course = pre[0];
        int prerequisite = pre[1];
        
        graph[prerequisite].push_back(course);  // Add the course to the graph
        inDegree[course]++;  // Increment the in-degree for the course
    }
    
    // Step 2: Initialize the queue with courses that have no prerequisites (in-degree 0)
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    
    // Step 3: Process the courses in the queue
    while (!q.empty()) {
        int currentCourse = q.front();
        q.pop();
        
        order.push_back(currentCourse);
        
        // Decrease in-degree for all neighbors (dependent courses)
        for (int nextCourse : graph[currentCourse]) {
            inDegree[nextCourse]--;
            if (inDegree[nextCourse] == 0) {
                q.push(nextCourse);  // If in-degree becomes 0, add it to the queue
            }
        }
    }
    
    // Step 4: Check if we processed all courses
    if (order.size() == numCourses) {
        return order;
    } else {
        return {};  // If not all courses are processed, there is a cycle
    }
}

// Example usage:
int main() {
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> prerequisites3 = {};
    
    vector<int> result1 = findOrder(2, prerequisites1);
    vector<int> result2 = findOrder(4, prerequisites2);
    vector<int> result3 = findOrder(1, prerequisites3);
    
    // Print results
    for (int course : result1) cout << course << " ";
    cout << endl;  // Expected output: [0, 1]

    for (int course : result2) cout << course << " ";
    cout << endl;  // Expected output: [0, 1, 2, 3] or [0, 2, 1, 3]
    
    for (int course : result3) cout << course << " ";
    cout << endl;  // Expected output: [0]
    
    return 0;
}
