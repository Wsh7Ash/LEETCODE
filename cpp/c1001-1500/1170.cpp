class Solution {
    private:
        int f(const string& s){
            char minChar = 'z';
            int count = 0;
    
            for(char c : s){
                if(c < minChar){
                    minChar = c;
                    count = 1;
                }else if(c == minChar){
                    count++;
                }
            }
            return count;
        }
    public:
        vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
            vector<int> wordFreqs;
            for(const string& word : words){
                wordFreqs.push_back(f(word));
            }
    
            sort(wordFreqs.begin(), wordFreqs.end());
    
            vector<int> res;
            for(const string& query : queries){
                int queryFreq = f(query);
                auto it = upper_bound(wordFreqs.begin(), wordFreqs.end(), queryFreq);
                res.push_back(distance(it, wordFreqs.end()));
            }
            return res;
    
        }
    };