class Solution {
    public:
        bool detectCapitalUse(string word) {
            int n = word.size();
            bool allUpper = true;
            bool allLower = true;
            bool firstUpper = true;
    
            for(char c : word){
                if(!isupper(c)){
                    allUpper = false;
                    break;
                }
            }
            if(allUpper) return true;
            for(char c : word){
                if(!islower(c)){
                    allLower = false;
                    break;
                }
            }
            if(allLower) return true;
    
            if(isupper(word[0])){
                for(int i =1; i <n; i++){
                    if(!islower(word[i])){
                        firstUpper = false;
                        break;
                    }
                }
                if(firstUpper) return true;
            }
            return false;
        }
    };