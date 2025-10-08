class Solution {
    public:
        int findTheLongestSubstring(string s) {
            
            unordered_map<int, int> stateToIndex;
    
            stateToIndex[0] = -1;
    
            int mask = 0;
            int maxLength = 0;
    
            for(int i = 0; i < s.length(); i++){
                switch(s[i]){
                    case 'a': mask ^= (1 << 0); break;
                    case 'e': mask ^= (1 << 1); break;
                    case 'i': mask ^= (1 << 2); break;
                    case 'o': mask ^= (1 << 3); break;
                    case 'u': mask ^= (1 << 4); break;
                    default: break;
                }
    
                if(stateToIndex.find(mask) != stateToIndex.end()){
                    int len = i - stateToIndex[mask];
                    maxLength = max(maxLength, len);
                }else{
                    stateToIndex[mask] = i;
                }
            }
            return maxLength;
        }
    };