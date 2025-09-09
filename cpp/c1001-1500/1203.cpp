class Solution {
    public:
        vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
            int groupID = m;
            for (int i = 0; i < n; i++) {
                if (group[i] == -1) {
                    group[i] = groupID++;
                }
            }
            
            vector<vector<int>> itemGraph(n);
            vector<vector<int>> groupGraph(groupID);
            vector<int> itemIndegree(n, 0);
            vector<int> groupIndegree(groupID, 0);
            
            for (int i = 0; i < n; i++) {
                int currentGroup = group[i];
                for (int before : beforeItems[i]) {
                    int beforeGroup = group[before];
                    itemGraph[before].push_back(i);
                    itemIndegree[i]++;
                    
                    if (currentGroup != beforeGroup) {
                        groupGraph[beforeGroup].push_back(currentGroup);
                        groupIndegree[currentGroup]++;
                    }
                }
            }
            
            vector<int> groupOrder;
            queue<int> q;
            for (int i = 0; i < groupID; i++) {
                if (groupIndegree[i] == 0) {
                    q.push(i);
                }
            }
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                groupOrder.push_back(cur);
                
                for (int neighbor : groupGraph[cur]) {
                    groupIndegree[neighbor]--;
                    if (groupIndegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            if (groupOrder.size() != groupID) {
                return {};
            }
            
            vector<vector<int>> groupItems(groupID);
            for (int i = 0; i < n; i++) {
                groupItems[group[i]].push_back(i);
            }
            
            vector<int> result;
            for (int g : groupOrder) {
                if (groupItems[g].empty()) continue;
                
                queue<int> itemQueue;
                vector<int> itemsInGroup = groupItems[g];
                
                for (int item : itemsInGroup) {
                    if (itemIndegree[item] == 0) {
                        itemQueue.push(item);
                    }
                }
                
                int count = 0;
                while (!itemQueue.empty()) {
                    int curItem = itemQueue.front();
                    itemQueue.pop();
                    count++;
                    result.push_back(curItem);
                    
                    for (int neighbor : itemGraph[curItem]) {
                        itemIndegree[neighbor]--;
                        if (group[neighbor] == g) {
                            if (itemIndegree[neighbor] == 0) {
                                itemQueue.push(neighbor);
                            }
                        }
                    }
                }
                
                if (count != itemsInGroup.size()) {
                    return {};
                }
            }
            
            return result;
        }
    };