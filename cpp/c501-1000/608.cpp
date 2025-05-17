#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct TreeNode {
    int id;
    int p_id;
    string type;
};

string determineType(int id, int p_id, const unordered_set<int>& parent_ids) {
    if (p_id == -1) { // Assuming -1 represents NULL in p_id
        return "Root";
    } else if (parent_ids.count(id) > 0) {
        return "Inner";
    } else {
        return "Leaf";
    }
}

vector<TreeNode> classifyTreeNodes(const vector<pair<int, int>>& tree_data) {
    unordered_set<int> parent_ids;
    vector<TreeNode> result;
    
    // First pass: collect all parent ids (excluding root)
    for (const auto& node : tree_data) {
        if (node.second != -1) { // -1 represents NULL in p_id
            parent_ids.insert(node.second);
        }
    }
    
    // Second pass: classify each node
    for (const auto& node : tree_data) {
        TreeNode tn;
        tn.id = node.first;
        tn.p_id = node.second;
        tn.type = determineType(node.first, node.second, parent_ids);
        result.push_back(tn);
    }
    
    // Sort by id as in the SQL query
    sort(result.begin(), result.end(), [](const TreeNode& a, const TreeNode& b) {
        return a.id < b.id;
    });
    
    return result;
}

int main() {
    // Example tree data: vector of (id, p_id) pairs
    // p_id = -1 represents NULL in p_id
    vector<pair<int, int>> tree_data = {
        {1, -1},
        {2, 1},
        {3, 1},
        {4, 2},
        {5, 2},
        {6, 3},
        {7, 3},
        {8, 4}
    };
    
    vector<TreeNode> classified_nodes = classifyTreeNodes(tree_data);
    
    // Print the result in a similar format to the SQL output
    cout << "id\ttype" << endl;
    for (const auto& node : classified_nodes) {
        cout << node.id << "\t" << node.type << endl;
    }
    
    return 0;
}