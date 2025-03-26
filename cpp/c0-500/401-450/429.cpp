/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // Result vector to store level-order traversal
        vector<vector<int>> result;
        
        // If tree is empty, return empty result
        if (!root) {
            return result;
        }
        
        // Queue for BFS
        queue<Node*> q;
        q.push(root);
        
        // Process nodes level by level
        while (!q.empty()) {
            // Get number of nodes at current level
            int levelSize = q.size();
            // Vector to store current level's values
            vector<int> currentLevel;
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                // Get next node from queue
                Node* node = q.front();
                q.pop();
                
                // Add node's value to current level
                currentLevel.push_back(node->val);
                
                // Add all children to queue for next level
                for (Node* child : node->children) {
                    if (child) {
                        q.push(child);
                    }
                }
            }
            
            // Add current level to result
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
Let's break down how this solution works:

Approach:
Use BFS with a queue to traverse tree level by level
For each level, process all nodes and collect their values
Add each node's children to queue for next level
Algorithm Steps:
If root is null, return empty result
Initialize queue with root node
While queue is not empty:
Get size of current level (number of nodes)
Process all nodes at current level
Add their values to current level vector
Add their children to queue
Add completed level to result
Key Features:
Uses queue to maintain order of processing
Processes nodes level by level
Handles variable number of children per node
Returns vector of vectors where each inner vector is a level
Example 1: [1,null,3,2,4,null,5,6]
Level 0: [1]
Level 1: [3,2,4]
Level 2: [5,6]
Output: [[1],[3,2,4],[5,6]]
Time and Space Complexity:
Time Complexity: O(n) where n is total number of nodes
Each node is processed exactly once
Space Complexity: O(w) where w is maximum width of tree
Queue stores at most one level of nodes at a time
Output space is O(n) but typically not counted
Handling Constraints:
Works for tree height ≤ 1000
Handles 0 to 10^4 nodes
Works with empty tree (returns empty vector)