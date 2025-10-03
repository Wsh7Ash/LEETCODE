class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            
            int n = status.size();
            vector<bool> hasBox(n, false);
            vector<bool> hasKey(n, false);
            vector<bool> opened(n, false);
            queue<int> q;
    
            int totalCandies = 0;
    
            for(int box : initialBoxes){
                hasBox[box] = true;
                if(status[box] == 1){
                    q.push(box);
                }
            }
    
            while(!q.empty()){
                int curBox = q.front();
                q.pop();
    
                if(opened[curBox]) continue;
    
                opened[curBox] = true;
                totalCandies += candies[curBox];
    
                for(int key : keys[curBox]){
                    hasKey[key] = true;
                    if(hasBox[key] && !opened[key]){
                        q.push(key);
                    }
                }
    
                for(int box : containedBoxes[curBox]){
                    hasBox[box] = true;
    
                    if((status[box] == 1 || hasKey[box]) && !opened[box]){
                        q.push(box);
                    }
                }
            }
            return totalCandies;
        }
    };