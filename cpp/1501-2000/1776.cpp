class Solution {
    public:
        vector<double> getCollisionTimes(vector<vector<int>>& cars) {
            int n = cars.size();
            vector<double> res(n, -1.0);
    
            vector<int> stack;
    
            for(int i = n - 1; i >= 0; i--){
                
                while(!stack.empty()){
                    int j = stack.back();
                
                    if(cars[i][1] <= cars[j][1]){
                        stack.pop_back();
                    }else{
                        if(res[j] == -1){
                            double time = (double)(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
                            res[i]  = time;
                            break;
                        }else{
                            double time = (double)(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
                            if(time <= res[j]){
                                res[i] = time;
                                break;
                            }else{
                                stack.pop_back();
                            }
                        }
                    }
                }
                stack.push_back(i);
            }
            return res;
        }
    };