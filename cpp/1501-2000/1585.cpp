class Solution {
    public:
        bool isTransformable(string s, string t) {
            int n = s.size();
            vector<queue<int>> pos(10);
    
            for(int i = 0; i < n; i++){
                pos[s[i] - '0'].push(i);
            }
    
            for(int i = 0; i < n; i++){
                int digit = t[i] - '0';
                if(pos[digit].empty()){
                    return false;
                }
                for(int d = 0; d < digit; d++){
                    if(!pos[d].empty() && pos[d].front() < pos[digit].front()){
                        return false;
                    }
                }
                pos[digit].pop();
            }
            return true;
        }
    };