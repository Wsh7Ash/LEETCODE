class Solution {
    public:
        int kSimilarity(string s1, string s2) {
            if(s1 == s2) return 0;
    
            queue<string> q;
            unordered_set<string> visited;
            q.push(s1);
            visited.insert(s1);
            int k = 0;
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    string cur = q.front();
                    q.pop();
                    if(cur == s2) return k;
                    int j = 0;
                    while(cur[j] == s2[j]) j++;
                    for(int m = j+1; m < s1.size(); m++){
                        if(cur[m] == s2[j] && cur [m] != s2[m]){
                            string next = cur;
                            swap(next[j], next[m]);
                            if(visited.find(next) == visited.end()){
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
                ++k;
            }
            return -1;
        }
    };