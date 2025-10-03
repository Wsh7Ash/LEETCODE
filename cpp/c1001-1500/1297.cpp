class Solution {
    public:
        int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
            unordered_map<string, int> subStringCount;
    
            for(int i = 0; i <= (int)s.length() - minSize; i++){
                string sub = s.substr(i, minSize);
    
                unordered_map<char, int> charCount;
                for(char c : sub){
                    charCount[c]++;
                }
    
                if(charCount.size() <= maxLetters){
                    subStringCount[sub]++;
                }
            }
    
            int maxOcc = 0;
            for(const auto& entry : subStringCount){
                maxOcc = max(maxOcc, entry.second);
            }
    
            return maxOcc;
        }
    };