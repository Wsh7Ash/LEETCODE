class Solution {
    public:
        vector<int> powerfulIntegers(int x, int y, int bound) {
            unordered_set<int> p;
            if(bound < 2) return {};
    
            vector<int> xp;
            if(x == 1) xp .push_back(1);
            else{
                int i = 0;
                while(true){
                    int power = pow(x, i);
                    if(power > bound) break;
                    xp.push_back(power);
                    i++;
                }
            }
            vector<int> yp;
            if(y == 1) yp .push_back(1);
            else{
                int j = 0;
                while(true){
                    int power = pow(y, j);
                    if(power > bound) break;
                    yp.push_back(power);
                    j++;
                }
            }
            for(int xi : xp){
                for(int yj : yp){
                    int sum_xy = xi + yj;
                    if(sum_xy <= bound){
                        p.insert(sum_xy);
                    }
                }
            }
            return vector<int>(p.begin(), p.end());
        }
    };