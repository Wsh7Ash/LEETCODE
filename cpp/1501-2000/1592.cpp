class Solution {
    public:
        string reorderSpaces(string text) {
            vector<string> words;
            stringstream ss(text);
            string word;
            int spaceCount = count(text.begin(), text.end(), ' ');
    
            while(ss >> word) words.push_back(word);
            int wordCount = words.size();
            if(wordCount == 1) return words[0] + string(spaceCount, ' ');
    
            int spaceBetween = spaceCount / (wordCount - 1);
            int extraSpaces = spaceCount % (wordCount - 1);
    
            string res;
            for(int i = 0; i < wordCount; i++){
                res += words[i];
                if(i < wordCount - 1){
                    res += string(spaceBetween, ' ');
                }
            }
            res += string(extraSpaces, ' ');
            
            return res;
        }
    };