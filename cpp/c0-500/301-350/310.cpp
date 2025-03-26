#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        
        // Build adjacency list
        std::vector<std::unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        // Find initial leaves (nodes with degree 1)
        std::queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push(i);
            }
        }
        
        // Trim leaves layer by layer
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            
            for (int i = 0; i < leavesCount; i++) {
                int leaf = leaves.front();
                leaves.pop();
                
                // Remove leaf from its neighbor
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                
                // If neighbor becomes a leaf, add to queue
                if (graph[neighbor].size() == 1) {
                    leaves.push(neighbor);
                }
            }
        }
        
        // Remaining nodes are the roots of MHTs
        std::vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
Let's break down how this works:

Approach:
In a tree, the minimum height is achieved when the root is at the "center"
By removing leaves layer by layer, we converge to the center
A tree can have at most 2 center nodes (for even-length paths)
Algorithm:
Build an adjacency list representation of the graph
Identify initial leaves (nodes with degree 1)
Repeatedly:
Remove all current leaves
Update neighbors and find new leaves
Continue until ≤ 2 nodes remain
Return remaining nodes
Key Insights:
A tree with n nodes has n-1 edges
Leaf nodes are furthest from the center
Final result will be 1 or 2 nodes
Here's a test program:

cpp
Wrap
Copy
#include <iostream>
#include <vector>

class Solution {
    // ... (same implementation as above)
};

void printResult(const std::vector<int>& result) {
    std::cout << "[";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    int n1 = 4;
    std::vector<std::vector<int>> edges1 = {{1,0}, {1,2}, {1,3}};
    std::cout << "Test 1: ";
    printResult(solution.findMinHeightTrees(n1, edges1));
    
    // Test case 2
    int n2 = 6;
    std::vector<std::vector<int>> edges2 = {{3,0}, {3,1}, {3,2}, {3,4}, {5,4}};
    std::cout << "Test 2: ";
    printResult(solution.findMinHeightTrees(n2, edges2));
    
    // Additional test cases
    int n3 = 1;
    std::vector<std::vector<int>> edges3;
    std::cout << "Test 3: ";
    printResult(solution.findMinHeightTrees(n3, edges3));
    
    return 0;
}
Expected Output:

text
Wrap
Copy
Test 1: [1]
Test 2: [3,4]
Test 3: [0]
Complexity:

Time: O(n) - we process each node once
Space: O(n) for the adjacency list and queue
Key Features:

Handles all edge cases (n=1, n=2)
Works within constraints:
1 ≤ n ≤ 2 * 10^4
edges.length = n-1
Valid node indices
Returns all possible MHT roots
Correctly identifies minimum height trees
The solution efficiently finds the centroids of the tree, which give the minimum height when used as roots. It handles both single-center and dual-center cases correctly and satisfies all the problem constraints.