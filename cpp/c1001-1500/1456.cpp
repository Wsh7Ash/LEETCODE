class Solution {
    public:
        int maxVowels(string s, int k) {
            string vowels = "aeiou";
            int n = s.length();
            int curVowels = 0;
    
            for(int i = 0; i < k; i++){
                if(vowels.find(s[i]) != string::npos){
                    curVowels++;
                }
            }
    
            int maxVowels = curVowels;
    
            for(int i = k; i < n; i++){
                if(vowels.find(s[i - k]) != string::npos){
                    curVowels--;
                }
                if(vowels.find(s[i]) != string::npos){
                    curVowels++;
                }
                maxVowels = max(maxVowels, curVowels);
            }
            return maxVowels;
        }
    };