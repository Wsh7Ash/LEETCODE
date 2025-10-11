class Solution {
    public:
        bool canConstruct(string s, int k) {
            int n = s.length();
            if(k > n) return false;
    
            vector<int> freq(26, 0);
            for(char c : s){
                freq[c - 'a']++;
            }
    
            int oddCount = 0;
            for(int  count : freq){
                if(count % 2 == 1){
                    oddCount++;
                }
            }
    
            return oddCount <= k;
        }
    };