class Solution {
    public:
        int longestWPI(vector<int>& hours) {
            int n = hours.size();
            int score = 0;
            int max_len = 0;
            unordered_map<int, int> first_oc;
    
            for(int i = 0; i < n; i++){
                score += (hours[i] > 8) ? 1 : -1;
    
                if(score > 0) max_len = i + 1;
                else{
                    if(first_oc.find(score - 1) != first_oc.end()){
                        max_len = max(max_len, i - first_oc[score - 1]);
                    }
                }
    
                if(first_oc.find(score) == first_oc.end()){
                    first_oc[score] = i;
                }
            }
            return max_len;
        }
    };