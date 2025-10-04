class Solution {
    public:
        bool canReach(vector<int>& arr, int start) {
            int n = arr.size();
            vector<bool> v(n, false);
            queue<int> q;
    
            q.push(start);
            v[start] = true;
    
            while(!q.empty()){
                int i = q.front();
                q.pop();
    
                if(arr[i] == 0) return true;
    
                int ni1 = i + arr[i];
                if(ni1 >= 0 && ni1 < n && !v[ni1]){
                    v[ni1] = true;
                    q.push(ni1);
                }
                int ni2 = i - arr[i];
                if(ni2 >= 0 && ni2 < n && !v[ni2]){
                    v[ni2] = true;
                    q.push(ni2);
                }
            }
            return false;
        }
    };