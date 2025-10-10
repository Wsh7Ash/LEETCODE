class Solution {
    public:
        int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
            
            unordered_map<int, int> reversedMap;
    
            for(auto& seat : reservedSeats){
                reversedMap[seat[0]] |= (1 << (seat[1] - 1));
            }
    
            int res = 0;
    
            int leftMask = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
            int middleMask = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
            int rightMask = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);
        
            for(auto& [row, mask] : reversedMap){
                int count = 0;
                if((mask & leftMask) == 0) count++;
                if((mask & rightMask) == 0) count++;
    
                if(count == 0 && (mask & middleMask) == 0) count = 1;
    
                res += count;
            }
    
            res += (n - reversedMap.size()) * 2;
    
            return res;
        }
    };