class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> ladderAllocations;
        for(int i = 0; i < heights.size() - 1; i++){
            int climb = heights[i+1] - heights[i];
            if(climb <= 0) continue;
            ladderAllocations.push(climb);
            if(ladderAllocations.size() > ladders){
                int smallestClimb = ladderAllocations.top();
                ladderAllocations.pop();
                if(bricks < smallestClimb) return i;
                bricks -= smallestClimb;
            }
        }
        return heights.size() - 1;
    }
};