class Solution {
    public:
        vector<int> numsSameConsecDiff(int n, int k) {
            vector<int> res;
            queue<int> q;
    
            for(int i = 1; i <= 9; i++){
                q.push(i);
            }
    
            for(int level = 1; level < n; level++){
                int size =q.size();
                for(int i = 0; i < size; i++){
                    int num = q.front();
                    q.pop();
                    int lastDigit = num % 10;
                    if(lastDigit + k <= 9){
                        q.push(num * 10 + (lastDigit + k));
                    }
                    if(k != 0 && lastDigit - k >= 0){
                        q.push(num * 10 + (lastDigit - k));
                    }
                }
            }
    
            while(!q.empty()){
                res.push_back(q.front());
                q.pop();
            }
            return res;
        }
    };