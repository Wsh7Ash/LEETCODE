class Solution {
    public:
        vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
            unordered_map<string, int> eval_map;
            for(int i = 0; i < evalvars.size(); i++){
                eval_map[evalvars[i]] = evalints[i];
            }
    
            vector<string> tokens = tokenize(expression);
            vector<string> rpn = toRPN(tokens);
            Polynomial result = evaluate(rpn, eval_map);
            return format(result);
        }
    
        struct Term{
            map<string, int> vars;   
            
            Term() {}
            Term(string var) { vars[var] = 1; }
    
            bool operator<(const Term& other) const{
                return vars < other.vars;
            }
    
            Term multiply(const Term& other) const {
                Term result = *this;
                for(const auto& p : other.vars){
                    result.vars[p.first] += p.second;
                }
                return result;
            }
            
            int getDegree() const {
                int degree = 0;
                for(const auto& p : vars) {
                    degree += p.second;
                }
                return degree;
            }
            
            string getVarString() const {
                string result;
                for(const auto& p : vars) {
                    for(int i = 0; i < p.second; i++) {
                        result += "*" + p.first;
                    }
                }
                return result;
            }
        };
    
        struct Polynomial {
            map<Term, int> terms;  
    
            Polynomial(){}
            
            Polynomial(int coeff){
                if(coeff != 0){
                    terms[Term()] = coeff;   
                }
            }
            
            Polynomial(string var){
                terms[Term(var)] = 1;
            }
    
            Polynomial operator+(const Polynomial& other) const{
                Polynomial res = *this;
                for(const auto& p : other.terms){
                    res.terms[p.first] += p.second;
                }
                res.clean();
                return res;
            }
            
            Polynomial operator-(const Polynomial& other) const{
                Polynomial res = *this;
                for(const auto& p : other.terms){
                    res.terms[p.first] -= p.second;
                }
                res.clean();
                return res;
            }
    
            Polynomial operator*(const Polynomial& other) const{
                Polynomial res;
                for(const auto& p1 : terms){
                    for(const auto& p2 : other.terms){
                        Term newTerm = p1.first.multiply(p2.first);
                        int newCoeff = p1.second * p2.second;
                        res.terms[newTerm] += newCoeff;
                    }
                }
                res.clean();
                return res;
            }
    
            void clean(){
                for(auto it = terms.begin(); it != terms.end(); ){
                    if(it->second == 0){
                        it = terms.erase(it);
                    }else{
                        it++;
                    }
                }
            }
        };
    
        vector<string> tokenize(const string& expr){
            vector<string> tokens;
            string token;
            for(char c : expr){
                if(c == ' '){
                    if(!token.empty()){
                        tokens.push_back(token);
                        token.clear();
                    }
                }else if(c == '(' || c == ')' || c == '+' || c == '-' || c == '*'){
                    if(!token.empty()){
                        tokens.push_back(token);
                        token.clear();
                    }
                    tokens.push_back(string(1, c));
                }else{
                    token += c;
                }
            }
            if(!token.empty()){
                tokens.push_back(token);
            }
            return tokens;
        }
    
        vector<string> toRPN(const vector<string>& tokens){
            vector<string> rpn;
            stack<string> ops;
            
            for(const string& token : tokens){
                if(token == "("){
                    ops.push(token);
                }else if(token == ")"){
                    while(!ops.empty() && ops.top() != "("){
                        rpn.push_back(ops.top());
                        ops.pop();
                    }
                    if(!ops.empty()) ops.pop();  
                }else if(token == "+" || token == "-"){
                    while(!ops.empty() && ops.top() != "(" && 
                          (ops.top() == "+" || ops.top() == "-" || ops.top() == "*")){
                        rpn.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(token);
                }else if(token == "*"){
                    while(!ops.empty() && ops.top() == "*"){
                        rpn.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(token);
                }else{
                    rpn.push_back(token);
                }
            }
            
            while(!ops.empty()){
                rpn.push_back(ops.top());
                ops.pop();
            }
            return rpn;
        }
    
        Polynomial evaluate(const vector<string>& rpn, unordered_map<string, int>& eval_map){
            stack<Polynomial> s;
            
            for(const string& token : rpn){
                if(token == "+"){
                    if(s.size() >= 2){
                        Polynomial a = s.top(); s.pop();
                        Polynomial b = s.top(); s.pop();
                        s.push(b + a);
                    }
                }
                else if(token == "-"){
                    if(s.size() >= 2){
                        Polynomial a = s.top(); s.pop();
                        Polynomial b = s.top(); s.pop();
                        s.push(b - a);
                    }
                }
                else if(token == "*"){
                    if(s.size() >= 2){
                        Polynomial a = s.top(); s.pop();
                        Polynomial b = s.top(); s.pop();
                        s.push(b * a);
                    }
                }
                else{
                    if((token[0] == '-' && token.length() > 1 && isdigit(token[1])) || 
                       (token[0] != '-' && isdigit(token[0]))){
                        s.push(Polynomial(stoi(token)));
                    }else if(eval_map.count(token)){
                        s.push(Polynomial(eval_map[token]));
                    }else{
                        s.push(Polynomial(token));
                    }
                }
            }
            
            return s.empty() ? Polynomial(0) : s.top();
        }
    
        vector<string> format(const Polynomial& poly){
            vector<pair<Term, int>> termList;
            for(const auto& p : poly.terms){
                if(p.second != 0){
                    termList.push_back({p.first, p.second});
                }
            }
            
            if(termList.empty()){
                return {};
            }
            
            sort(termList.begin(), termList.end(), [](const pair<Term, int>& a, const pair<Term, int>& b) {
                int degreeA = a.first.getDegree();
                int degreeB = b.first.getDegree();
                
                if(degreeA != degreeB) {
                    return degreeA > degreeB;
                }
                
                string varsA = a.first.getVarString();
                string varsB = b.first.getVarString();
                
                return varsA < varsB;
            });
            
            vector<string> result;
            for(const auto& p : termList){
                string term = to_string(p.second) + p.first.getVarString();
                result.push_back(term);
            }
            
            return result;
        }
    };