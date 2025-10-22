class ThroneInheritance {
    private:
        string kingName;
        unordered_map<string, vector<string>> children;
        unordered_set<string> dead;
    public:
        ThroneInheritance(string kingName) {
            this->kingName = kingName;
        }
        
        void birth(string parentName, string childName) {
            children[parentName].push_back(childName);    
        }
        
        void death(string name) {
            dead.insert(name);
        }
        
        vector<string> getInheritanceOrder() {
            vector<string> inh;
            dfs(kingName, inh);
            return inh;
        }
    private:
        void dfs(string person, vector<string>& inh){
            if(dead.find(person) == dead.end()){
                inh.push_back(person);
            }
            for(string child : children[person]){
                dfs(child, inh);
            }
        }
    };
    
    /**
     * Your ThroneInheritance object will be instantiated and called as such:
     * ThroneInheritance* obj = new ThroneInheritance(kingName);
     * obj->birth(parentName,childName);
     * obj->death(name);
     * vector<string> param_3 = obj->getInheritanceOrder();
     */