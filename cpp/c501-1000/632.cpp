class Solution {
    public:
        vector<int> smallestRange(vector<vector<int>>& nums) {
            int k = nums.size();
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
            int curMax = INT_MIN;
            vector<int> pointers(k, 0);
    
            for(int i = 0; i < k; i++){
                if(!nums[i].empty()){
                    minHeap.push({nums[i][0], {i, 0}});
                    curMax = max(curMax, nums[i][0]);
                }
            }
            int rangeStart = -1;
            int rangeEnd = -1;
            int minRange = INT_MAX;
    
            while(minHeap.size() == k){
                auto cur = minHeap.top();
                minHeap.pop();
                int curVal = cur.first;
                int listIndex = cur.second.first;
                int elementIndex = cur.second.second;
    
                if(curMax - curVal < minRange){
                    minRange = curMax - curVal;
                    rangeStart = curVal;
                    rangeEnd = curMax;
                }
                if(elementIndex + 1 < nums[listIndex].size()){
                    int nextVal = nums[listIndex][elementIndex + 1];
                    minHeap.push({nextVal, {listIndex, elementIndex + 1}});
                    curMax = max(curMax, nextVal);
                }
            }
            return {rangeStart, rangeEnd};
        }
    };