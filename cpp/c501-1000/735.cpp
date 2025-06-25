class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> s;
            for(int ast : asteroids){
                bool exploded = false;
                while(!s.empty() && ast < 0 && s.top() > 0){
                    if(s.top() < -ast){
                        s.pop();
                        continue;
                    }else if(s.top() == -ast){
                        s.pop();
                    }
                    exploded = true;
                    break;
                }
                if(!exploded){
                    s.push(ast);
                }
            }
            vector<int> res(s.size());
            for(int i = res.size() - 1; i >= 0; i--){
                res[i] = s.top();
                s.pop();
            }
            return res;
        }
    };