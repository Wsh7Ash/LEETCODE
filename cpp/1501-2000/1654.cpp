class Solution {
    public:
        int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
            int max_bound = 6000;
            unordered_set<int> forbidden_set(forbidden.begin(), forbidden.end());
            vector<vector<bool>> visited(max_bound + 1, vector<bool>(2, false));
            queue<pair<int, int>> q;
            q.push({0, false});
            visited[0][0] = true;
    
            int jumps = 0;
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    auto [pos, last_backward] = q.front();
                    q.pop();
                    if(pos == x) return jumps;
                    int next_forward = pos + a;
                    if(next_forward <= max_bound && !forbidden_set.count(next_forward) && !visited[next_forward][0]){
                        visited[next_forward][0] = true;
                        q.push({next_forward, false});
                    }
                    if(!last_backward){
                        int next_backward = pos - b;
                        if(next_backward >= 0 && !forbidden_set.count(next_backward) && !visited[next_backward][1]){
                            visited[next_backward][1] = true;
                            q.push({next_backward, true});
                        }
                    }
                }
                jumps++;
            }
            return -1;
        }
    };