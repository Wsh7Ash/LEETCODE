class Solution {
    public:
        bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
            
            vector<int> inDegree(n, 0);
            for(int i = 0; i < n; i++){
                if(leftChild[i] != -1){
                    inDegree[leftChild[i]]++;
                }
                if(rightChild[i] != -1){
                    inDegree[rightChild[i]]++;
                }
            }
    
            int root = -1;
            for(int i = 0; i <n; i++){
                if(inDegree[i] == 0){
                    if(root == -1){
                        root = i;
                    }else{
                        return false;
                    }
                }else if(inDegree[i] > 1){
                    return false;
                }
            }
    
            if(root == -1) return false;
    
    
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(root);
            visited[root] = true;
            int visitedCount = 0;
    
            while(!q.empty()){
                int node = q.front();
                q.pop();
                visitedCount++;
    
                if(leftChild[node] != -1){
                    if(visited[leftChild[node]]){
                        return false;
                    }
                    visited[leftChild[node]] = true;
                    q.push(leftChild[node]);
                }
                
                if(rightChild[node] != -1){
                    if(visited[rightChild[node]]){
                        return false;
                    }
                    visited[rightChild[node]] = true;
                    q.push(rightChild[node]);
                }
            }
            return visitedCount == n;
        }
    };