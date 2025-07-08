/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    public:
        void findSecretWord(vector<string>& words, Master& master) {
            vector<string> cans = words;
            while(!cans.empty()){
                string gword = getBestMatches(cans);
                int matches = master.guess(gword);
                if(matches == 6) return;
    
                vector<string> new_cans;
                for(const string& word : cans){
                    if(countMatches(word, gword) == matches){
                        new_cans.push_back(word);
                    }
                }
                cans = new_cans;
            }
        }
    
        string getBestMatches(const vector<string>& cans){
            int mm_size = INT_MAX;
            string bguess;
            for(const string& guess : cans){
                vector<int> groups(7, 0);
                for(const string& word : cans){
                    int matches = countMatches(word, guess);
                    groups[matches]++;
                }
                int cur_max = *max_element(groups.begin(), groups.end());
                if(cur_max < mm_size){
                    mm_size = cur_max;
                    bguess = guess;
                }
            }
            return bguess;
        }
    
        int countMatches(const string& a, const string& b){
            int matches = 0;
            for(int i = 0; i < a.size(); i++){
                if(a[i] == b[i]) matches++;
            }
            return matches;
        }
    };