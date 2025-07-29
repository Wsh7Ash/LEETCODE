class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            if (!root) return {};
            
            map<int, vector<pair<int, int>>> columnMap;
            queue<pair<TreeNode*, pair<int, int>>> q;
            q.push({root, {0, 0}});
            
            while (!q.empty()) {
                int levelSize = q.size();
                for (int i = 0; i < levelSize; ++i) {
                    auto nodeInfo = q.front();
                    q.pop();
                    TreeNode* node = nodeInfo.first;
                    int row = nodeInfo.second.first;
                    int col = nodeInfo.second.second;
                    
                    columnMap[col].emplace_back(row, node->val);
                    
                    if (node->left) q.push({node->left, {row + 1, col - 1}});
                    if (node->right) q.push({node->right, {row + 1, col + 1}});
                }
            }
            
            vector<vector<int>> res;
            for (auto& entry : columnMap) {
                auto& nodes = entry.second;
                sort(nodes.begin(), nodes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                    if (a.first != b.first) {
                        return a.first < b.first;
                    } else {
                        return a.second < b.second;
                    }
                });
                vector<int> columnValues;
                for (auto& node : nodes) {
                    columnValues.push_back(node.second);
                }
                res.push_back(columnValues);
            }
            return res;
        }
    };