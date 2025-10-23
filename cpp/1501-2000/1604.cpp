class Solution {
    public:
        vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
            unordered_map<string, vector<int>> accessMap;
            for(int i = 0; i < keyName.size(); i++){
                string timeStr = keyTime[i];
                int hours = stoi(timeStr.substr(0,2));
                int minutes = stoi(timeStr.substr(3,2));
                int totalMinutes = hours * 60 + minutes;
                accessMap[keyName[i]].push_back(totalMinutes);
            }
            set<string> alertedWorkers;
    
            for(auto& [name, times] : accessMap){
                if(times.size() < 3) continue;
                sort(times.begin(), times.end());
                for(int i = 2; i < times.size(); i++){
                    if(times[i] - times[i - 2] <= 60){
                        alertedWorkers.insert(name);
                        break;
                    }
                }
            }
    
            return vector<string>(alertedWorkers.begin(), alertedWorkers.end());
        }
    };