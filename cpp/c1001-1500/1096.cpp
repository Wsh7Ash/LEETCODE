class Solution {
    public:
        vector<string> braceExpansionII(string expression) {
            int idx = 0;
            set<string> res = parse(expression, idx);
            return vector<string>(res.begin(), res.end());
        }
    private:
        set<string> parse(string& expr, int& idx){
            set<string> res;
            while(idx < expr.size() && expr[idx] != '}'){
                if(expr[idx] == ','){
                    idx++;
                    continue;
                }
                set<string> term = parseItem(expr, idx);
                res.insert(term.begin(), term.end());
            }
            return res;
        }
    
        set<string> parseItem(string& expr, int& idx){
            set<string> res = {""};
            while(idx < expr.size() && expr[idx] != '}' && expr[idx] != ','){
                set<string> next;
                if(expr[idx] == '{'){
                    idx++;
                    set<string> inner = parse(expr, idx);
                    if(idx < expr.size() && expr[idx] == '}') idx++;
                    for(const string& a : res){
                        for(const string& b : inner){
                            next.insert(a + b);
                        }
                    }
                }else{
                    string s;
                    while(idx < expr.size() && isalpha(expr[idx])){
                        s += expr[idx++];
                    }
                    set<string> single = {s};
                    for(const string& a : res){
                        for(const string& b : single){
                            next.insert(a + b);
                        }
                    }
                }
                res = move(next);
            }
            return res;
        }
    };