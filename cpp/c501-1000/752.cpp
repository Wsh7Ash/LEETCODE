class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            unordered_set<string> dead(deadends.begin(), deadends.end());
            unordered_set<string> visited;
            queue<string> q;
            string start = "0000";
    
            if(dead.find(start) != dead.end()){
                return -1;
            }
    
            q.push(start);
            visited.insert(start);
            int moves = 0;
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    string cur = q.front();
                    q.pop();
    
                    if(cur == target){
                        return moves;
                    }
                    for(int j = 0; j < 4; j++){
                        for(int k =-1; k <= 1; k+=2){
                            string next = cur;
                            char& c = next[j];
                            c = (c - '0' + k + 10) % 10 + '0';
    
                            if(dead.find(next) == dead.end() && visited.find(next) == visited.end()){
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
                moves++;
            }
    
            return -1;
        }
    };