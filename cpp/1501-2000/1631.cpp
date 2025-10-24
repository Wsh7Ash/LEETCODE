class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int rows = heights.size();
            int cols = heights[0].size();
    
            int left = 0;
            int right = 1e6;
            int res = right;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(canReach(heights, mid)){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return res;
        }
    
    private:
        bool canReach(vector<vector<int>>& heights, int maxEffort){
            int rows = heights.size();
            int cols = heights[0].size();
    
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
            queue<pair<int,int>>q;
            q.push({0,0});
            visited[0][0] = true;
    
            while(!q.empty()){
                auto [row, col] = q.front();
                q.pop();
                if(row == rows - 1 && col == cols - 1){
                    return true;
                }
                for(auto& dir : dirs){
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]){
                        int effort = abs(heights[newRow][newCol] - heights[row][col]);
                        if(effort <= maxEffort){
                            visited[newRow][newCol] = true;
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
            return false;
        }
    };