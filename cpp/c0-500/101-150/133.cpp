#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // Edge case: empty graph

        // HashMap to map original nodes to their clones
        unordered_map<Node*, Node*> visited;

        // Start DFS traversal
        return dfsClone(node, visited);
    }

private:
    Node* dfsClone(Node* node, unordered_map<Node*, Node*>& visited) {
        // If the node is already cloned, return its clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a clone of the current node
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode; // Mark the node as visited

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfsClone(neighbor, visited));
        }

        return cloneNode;
    }
};

int main() {
    // Example 1:
    // Construct the graph: [[2,4],[1,3],[2,4],[1,3]]
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Output the cloned graph (for verification)
    // Note: In practice, you would need a way to serialize the graph to verify the output.
    // This is just a placeholder to demonstrate usage.
    cout << "Cloned graph starting from node with value: " << clonedGraph->val << endl;

    return 0;
}