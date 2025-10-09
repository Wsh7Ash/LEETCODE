class Solution {
    public:
        int numTimesAllBlue(vector<int>& flips) {
            int count = 0; 
            int maxPos = 0;
            
            for(int i =0; i < flips.size(); i++){
                maxPos = max(maxPos, flips[i]);
    
                if(maxPos == i + 1) count++;
            }
    
            return count;
        }
    };