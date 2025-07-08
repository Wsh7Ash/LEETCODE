class Solution {
    public:
        vector<int> splitIntoFibonacci(string num) {
            vector<int> res;
            backtrack(num, res, 0);
            return res;
        }
    
        bool backtrack(const string& num, vector<int>& res, int index){
            if(index == num.size() && res.size() >= 3) return true;
    
            for(int i = index; i < num.size(); i++){
                if(i > index && num[index] == '0'){
                    break;
                }
    
                long long cur = stoll(num.substr(index, i - index + 1));
                if(cur > INT_MAX){
                    break;
                }
                int size = res.size();
                if(size >= 2){
                    long long sum = (long long)res[size-1] + res[size-2];
                    if(cur < sum){
                        continue;
                    }else if(cur > sum){
                        break;
                    }
                }
                res.push_back((int)cur);
                if(backtrack(num, res, i + 1)){
                    return true;
                }
                res.pop_back();
            }
            return false;
    
        }
    };