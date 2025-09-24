class Solution {
    public:
        vector<string> removeSubfolders(vector<string>& folder) {
            sort(folder.begin(), folder.end());
    
            vector<string> res;
            string curParent = "";
    
            for(const string& f : folder){
                if(curParent.empty() || f.find(curParent + "/") != 0){
                    res.push_back(f);
                    curParent = f;
                }
            }
            return res;
        }
    };