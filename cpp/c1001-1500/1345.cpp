class Solution {
    public:
        int minJumps(vector<int>& arr) {
            int n = arr.size();
            if(n <= 1) return 0;
    
            unordered_map<int, vector<int>> valueToIndices;
            for(int i = 0; i < n; i++){
                valueToIndices[arr[i]].push_back(i);
            }
    
            vector<int> visited(n, false);
            queue<int> q;
            q.push(0);
            visited[0] = true;
            int steps = 0;
    
            while(!q.empty()){
                int size = q.size();
    
                for(int i = 0; i < size; i++){
                    int index = q.front();
                    q.pop();
    
                    if(index == n - 1){
                        return steps;
                    }
    
                    if(index - 1 >= 0 && !visited[index - 1]){
                        visited[index - 1] = true;
                        q.push(index - 1);
                    }
    
                    if(index + 1 < n && !visited[index + 1]){
                        visited[index + 1] = true;
                        q.push(index + 1);
                    }
    
                    if(valueToIndices.find(arr[index]) != valueToIndices.end()){
                        for(int nextIndex : valueToIndices[arr[index]]){
                            if(!visited[nextIndex]){
                                visited[nextIndex] = true;
                                q.push(nextIndex);
                            }
                        }
                        valueToIndices.erase(arr[index]);
                    }
                }
                steps++;
            }
    
            return -1;
        }
    };