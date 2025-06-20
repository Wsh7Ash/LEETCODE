class Solution {
    public:
        string countOfAtoms(string formula) {
            stack<map<string, int>> s;
            s.push({});
            int i = 0, n = formula.size();
    
            while(i < n){
                if(formula[i] == '('){
                    s.push({});
                    i++;
                }else if(formula[i] == ')'){
                    i++;
                    int num = 0;
                    while(i < n && isdigit(formula[i])){
                        num = num * 10 + (formula[i] - '0');
                        i++;
                    }
                    num = num == 0 ? 1 : num;
                    auto cur = s.top();
                    s.pop();
                    for(auto& [atom, count] : cur){
                        s.top()[atom] += count * num;
                    }
                }else{
                    string atom;
                    atom += formula[i++];
                    while(i < n && islower(formula[i])){
                        atom  += formula[i++];
                    }
                    int num = 0;
                    while(i < n && isdigit(formula[i])){
                        num = num * 10 + (formula[i] - '0');
                        i++;
                    }
                    num = num == 0 ? 1 : num;
                    s.top()[atom] += num;
                }
            }
            map<string, int> counts = s.top();
            string res;
            for(auto& [atom, count] : counts){
                res += atom;
                if(count > 1){
                    res += to_string(count);
                }
            }
            return res;
        }
    };