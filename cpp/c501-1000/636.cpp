class Solution {
    public:
        vector<int> exclusiveTime(int n, vector<string>& logs) {
            vector<int> res(n, 0);
            stack<pair<int, int>> stk;
            int prevtime = 0;
            for(string& log : logs){
                size_t colon1 = log.find(':');
                size_t colon2 = log.find(':', colon1 + 1);
    
                int fid = stoi(log.substr(0, colon1));
                string type = log.substr(colon1 + 1, colon2 - colon1 - 1);
                int time = stoi(log.substr(colon2 + 1));
    
                if(type == "start"){
                    if(!stk.empty()){
                        int prevfid = stk.top().first;
                        res[prevfid] += time - prevtime;
                    }
                    stk.push({fid, time});
                    prevtime = time;
                }else{
                    int startfid = stk.top().first;
                    res[startfid] += time - prevtime + 1;
                    stk.pop();
                    prevtime = time + 1;
                }
            }
            return res;
        }
    };