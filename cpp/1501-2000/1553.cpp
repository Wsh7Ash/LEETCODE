class Solution {
    public:
        int minDays(int n) {
            queue<int> q;
            unordered_set<int> visited;
            q.push(n);
            visited.insert(n);
            int days = 0;
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    int cur = q.front();
                    q.pop();
                    if(cur == 0) return days;
                    if(visited.find(cur - 1) == visited.end()){
                        visited.insert(cur - 1);
                        q.push(cur - 1);
                    }
                    if(cur % 2 == 0 && visited.find(cur / 2) == visited.end()){
                        visited.insert(cur / 2);
                        q.push(cur / 2);
                    }
                    if(cur % 3 == 0 && visited.find(cur / 3) == visited.end()){
                        visited.insert(cur / 3);
                        q.push(cur / 3);
                    }
                }
                days++;
            }
            return days;
        }
    };