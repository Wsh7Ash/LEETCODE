class Solution {
    public:
        int balancedString(string s) {
            int n = s.length();
            int target = n / 4;
    
            unordered_map<char, int> freq;
            for(char c : s){
                freq[c]++;
            }
    
            if(freq['Q'] == target && freq['W'] == target && freq['E'] == target && freq['R'] == target){
                return 0;
            }
    
            int l = 0, ml = n;
    
            for(int r = 0; r <= n; r++){
                freq[s[r]]--;
    
                while(l <= r && 
                        freq['Q'] <= target &&
                        freq['W'] <= target &&
                        freq['E'] <= target &&
                        freq['R'] <= target)
                        {
                            ml = min(ml, r - l + 1);
    
                            freq[s[l]]++;
                            l++;
                        }
            }
            return ml;
        }
    };