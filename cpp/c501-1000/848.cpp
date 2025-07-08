class Solution {
    public:
        string shiftingLetters(string s, vector<int>& shifts) {
            int n = s.size();
            vector<long long> cumulativeShifts(n, 0);
    
            cumulativeShifts[n-1] = shifts[n-1];
            for(int i = n-2; i >= 0; i--){
                cumulativeShifts[i] = cumulativeShifts[i+1] + shifts[i];
            }
    
            for(int i = 0; i < n; i++){
                long long shift = cumulativeShifts[i];
                char c  = s[i];
    
                shift %=26;
                int newChar = c + shift;
                if(newChar > 'z'){
                    newChar -= 26;
                }
                s[i] = static_cast<char>(newChar);
            }
            return s;
    
        }
    };