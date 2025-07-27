class Solution {
    public:
        vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
            unordered_set<string> exact(wordlist.begin(), wordlist.end());
            unordered_map<string, string> case_insensitive;
            unordered_map<string, string> vowel_insensitive;
        
            for(const string& word : wordlist){
                string lower = to_lower(word);
                if(case_insensitive.find(lower) == case_insensitive.end()){
                    case_insensitive[lower] = word;
                }
                
                string vowel = replace_vowel(lower);
                if(vowel_insensitive.find(vowel) == vowel_insensitive.end()){
                    vowel_insensitive[vowel] = word;
                }
            }
    
            vector<string> res;
            for(const string& query : queries){
                if(exact.find(query) != exact.end()){
                    res.push_back(query);
                    continue;
                }
    
                string lower = to_lower(query);
                if(case_insensitive.find(lower) != case_insensitive.end()){
                    res.push_back(case_insensitive[lower]);
                    continue;
                
                }
    
                string vowel = replace_vowel(-r);
                if(vowel_insensitive.find(vowel) != vowel_insensitive.end()){
                    res.push_back(vowel_insensitive[vowel]);
                    continue;
                }
    
                res.push_back("");
            }
            return res;
        }
    
    private:
        string to_lower(const string& s){
            string res;
            for(char c : s){
                res += tolower(c);
            }
            return res;
        }
    
        string replace_vowel(const string& s){
            string res;
            for(char c : s){
                if(is_vowel(c)){
                    res += "*";
                }else{
                    res += c;
                }
            }
            return res;
        }
    
        bool is_vowel(char c){
            c = tolower(c);
            return c =='a' || c=='e' || c =='i' || c== 'o' || c=='u';
        }
    };