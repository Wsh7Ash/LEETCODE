class Solution {
    public:
        bool buddyStrings(string s, string goal) {
            if(s.size() != goal.size()) return false;
    
            vector<int> diff_indices;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != goal[i]){
                    diff_indices.push_back(i);
                }
            }
    
            if(diff_indices.size() == 2){
                swap(s[diff_indices[0]], s[diff_indices[1]]);
                return s == goal;
            }else if(diff_indices.empty()){
                unordered_set<char> seen;
                for(char c : s){
                    if(seen.count(c)){
                        return true;
                    }
                    seen.insert(c);
                }
                return false;
            }else{
                return false;
            }
        }
    };