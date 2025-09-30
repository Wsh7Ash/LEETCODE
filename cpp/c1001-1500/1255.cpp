class Solution {
    public:
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
            vector<int> letterCount(26, 0);
            for(char c : letters){
                letterCount[c - 'a']++;
            }
    
            return backtrack(words, letterCount, score, 0);
        }
    private:
        int backtrack(vector<string>& words, vector<int>& letterCount, vector<int>& score, int index){
            if(index == words.size()) return 0;
    
            int maxScore = backtrack(words, letterCount, score, index + 1);
    
            vector<int> wordCount(26, 0);
            int wordScore = 0;
    
            for(char c : words[index]){
                wordCount[c - 'a']++;
                wordScore += score[c - 'a'];
            }
    
            bool canTake = true;
            for(int i = 0; i < 26; i++){
                if(wordCount[i] > letterCount[i]){
                    canTake = false;
                    break;
                }
            }
    
            if(canTake){
                for(int i = 0; i < 26; i++){
                    letterCount[i] -= wordCount[i];
                }
    
                int scoreWithCurWord = wordScore + backtrack(words, letterCount, score, index + 1);
                maxScore = max(maxScore, scoreWithCurWord);
    
                for(int i = 0; i < 26; i++){
                    letterCount[i] += wordCount[i];
                }
            }
            return maxScore;
        }
    };