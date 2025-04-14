class Solution {
    public:
        int leastBricks(vector<vector<int>>& wall) {
           unordered_map<int, int> edgeCount;
           int maxEdge = 0;
    
           for(auto& row : wall){
            long long pos = 0;
            for(int i = 0; i < row.size() - 1; i++){
                pos += row[i];
                edgeCount[pos]++;
                maxEdge = max(maxEdge, edgeCount[pos]);
            }
           } 
           return wall.size() - maxEdge;
        }
    };