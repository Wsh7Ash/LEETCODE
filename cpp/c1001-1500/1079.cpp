class Solution {
    public:
        int numTilePossibilities(string tiles) {
          unordered_map<char, int> freq;
          for(char c : tiles){
            freq[c]++;
          }  
          int count = 0;
          bt(freq, count);
          return count;
        }
    
        void bt(unordered_map<char, int>& freq, int& count){
            for(auto& entry : freq){
                if(entry.second > 0){
                    count++;
                    entry.second--;
                    bt(freq, count);
                    entry.second++;
                }
            }
        }
    };