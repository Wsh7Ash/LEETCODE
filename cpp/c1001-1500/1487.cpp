class Solution {
    public:
        vector<string> getFolderNames(vector<string>& names) {
            unordered_map<string, int> count;
            vector<string> res;
    
            for(const string& name : names){
                if(count.find(name) == count.end()){
                    res.push_back(name);
                    count[name] = 1;
                }else{
                    int k = count[name];
                    string newName;
    
                    do{
                        newName = name + "(" + to_string(k) + ")";
                        k++;
                    }while(count.find(newName) != count.end());
    
                    res.push_back(newName);
                    count[name] = k;
                    count[newName] = 1;
                }
            }
            return res;
        }
    };