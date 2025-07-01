class Solution {
    public:
        vector<string> subdomainVisits(vector<string>& cpdomains) {
            unordered_map<string, int> dc;
            for(const string& cpd : cpdomains){
                size_t sp = cpd.find(' ');
                int count = stoi(cpd.substr(0, sp));
                string d = cpd.substr(sp + 1);
    
                vector<string> sds;
                size_t start = 0;
                size_t end = d.find('.');
    
                while(end != string::npos){
                    sds.push_back(d.substr(start));
                    start = end + 1;
                    end = d.find('.', start);
                }
                sds.push_back(d.substr(start));
    
                for(const string& sd : sds){
                    dc[sd] += count;
                }
            }
            vector<string> res;
            for(const auto& e : dc){
                res.push_back(to_string(e.second) + " "+ e.first);
            }
            return res;
        }
    };