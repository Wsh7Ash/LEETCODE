class Solution {
    public:
        vector<string> reorderLogFiles(vector<string>& logs) {
            vector<string> letterLogs;
            vector<string> digitLogs;
    
            for(const string& log : logs){
                int spacePos = log.find(' ');
                if(isalpha(log[spacePos + 1])){
                    letterLogs.push_back(log);
                }else{
                    digitLogs.push_back(log);
                }
            }
    
            auto comparator = [](const string& a, const string& b){
                int spacePosA = a.find(' ');
                string idA = a.substr(0, spacePosA);
                string contentA = a.substr(spacePosA + 1);
    
                int spacePosB = b.find(' ');
                string idB = b.substr(0, spacePosB);
                string contentB = b.substr(spacePosB + 1);
    
                if(contentA == contentB){
                    return idA < idB;
                }else{
                    return contentA < contentB;
                }
            };
    
            sort(letterLogs.begin(), letterLogs.end(),  comparator);
    
            vector<string> res;
            res.insert(res.end(), letterLogs.begin(), letterLogs.end());
            res.insert(res.end(), digitLogs.begin(), digitLogs.end());
            return res;
        }
    };