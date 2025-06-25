class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int num = left; num <= right; num++){
            if(isSelfDividing(num)){
                res.push_back(num);
            }
        }
        return res;
    }

    bool isSelfDividing(int num){
        int o = num;
        while(num > 0){
            int d = num % 10;
            if(d == 0 || o % d != 0){
                return false;
            }
            num /= 10;
        }
        return true;
    }
};