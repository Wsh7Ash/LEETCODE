class Solution {
    public:
        vector<string> findWords(vector<string>& words) {
            unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
            unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
            unordered_set<char> row3{'z','x','c','v','b','n','m',};
    
            vector<string> res;
    
            for(string word : words){
                char f = tolower(word[0]);
                unordered_set<char>* curRow;
    
                if(row1.count(f)) curRow = &row1;
                else if(row2.count(f)) curRow = &row2;
                else curRow = &row3;
    
                bool valid = true;
                for(char c : word){
                    if(!curRow->count(tolower(c))){
                        valid = false;
                        break;
                    }
                }
                if(valid) res.push_back(word);
            }
            return res;
        }
    };