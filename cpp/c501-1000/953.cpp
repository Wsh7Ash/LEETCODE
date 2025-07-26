class Solution {
    public:
        bool isAlienSorted(vector<string>& words, string order) {
            unordered_map<char, int> order_map;
            for(int i = 0; i < order.size(); i++){
                order_map[order[i]] = i;
            }
    
            for(int i = 0; i < words.size() - 1; i++){
                string word1 = words[i];
                string word2 = words[i + 1];
    
                int min_len = min(word1.size(), word2.size());
                bool is_valid = false;
                for(int j = 0; j < min_len; j++){
                    if(word1[j] != word2[j]){
                        if(order_map[word1[j]] > order_map[word2[j]]) return false;
                        is_valid = true;
                        break;
                    }
                }
                if(!is_valid && word1.size()  > word2.size()) return false;
            }
            return true;
        }
    };