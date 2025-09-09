class Solution {
    public:
        vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
            unordered_map<int, int> freq;
            for(string& word : words){
                int mask = 0;
                for(char c : word){
                    mask |= (1 << (c - 'a'));
                }
                freq[mask]++;
            }
    
            vector<int> res;
            for(string& p : puzzles){
                int puzzle_mask = 0;
                for(char c : p){
                    puzzle_mask |= (1 << (c - 'a'));
                }
                int first = p[0] - 'a';
                int rest = puzzle_mask & ~(1 << first);
    
                int count = 0; 
                int subset = rest;
                do{
                    int s = subset | (1 << first);
                    if(freq.find(s) != freq.end()){
                        count += freq[s];
                    }
                    subset = (subset - 1) & rest;
                }while(subset != rest);
    
                res.push_back(count);
            }
            return res;
        }
    };