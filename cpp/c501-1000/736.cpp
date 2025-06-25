class Solution {
    public:
        int evaluate(string expression) {
            unordered_map<string, int> g;
            return eval(expression, g);
        }
        int eval(const string& ex, unordered_map<string, int> vs){
            if(ex[0] != '('){
                if(isdigit(ex[0]) || ex[0] == '-'){
                    return stoi(ex);
                }else{
                    return vs[ex];
                }
            }
            string s = ex.substr(1, ex.size() - 2);
            vector<string> toks = parse(s);
    
            if(toks[0] == "let"){
                for(int i = 1; i < toks.size() - 1; i+=2){
                    string var = toks[i];
                    int val = eval(toks[i+1], vs);
                    vs[var] = val;
                }
                return eval(toks.back(), vs);
            }else if(toks[0] == "add"){
                int a = eval(toks[1], vs);
                int b = eval(toks[2], vs);
                return a + b;
            }else if(toks[0] == "mult"){
                int a = eval(toks[1], vs);
                int b = eval(toks[2], vs);
                return a * b;
            }
            throw invalid_argument("Invalid expression");
        }
    
        vector<string> parse(const string& s){
            vector<string> toks;
            string tok;
            int  p = 0;
    
            for(char c : s){
                if(c == '('){
                    p++;
                }else if(c == ')'){
                    p--;
                }
                if(p == 0 && c == ' '){
                    toks.push_back(tok);
                    tok.clear();
                }else{
                    tok += c;
                }
            }
            if(!tok.empty()){
                toks.push_back(tok);
            }
            return toks;
        }
    };