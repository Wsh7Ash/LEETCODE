class Solution {
    public:
        vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
            set<int> available;
            for(int i = 0; i < k; i++){
                available.insert(i);
            }
            vector<int> count(k, 0);
            for(int i = 0; i < arrival.size(); i++){
                int curTime = arrival[i];
                int reqLoad = load[i];
                while(!busy.empty() && busy.top().first <= curTime){
                    int server = busy.top().second;
                    busy.pop();
                    available.insert(server);
                }
                if(available.empty()) continue;
                int startServer = i % k;
                auto it = available.lower_bound(startServer);
                if(it == available.end()) it = available.begin();
                int assignedServer = *it;
                available.erase(it);
                count[assignedServer]++;
                int completionTime = curTime + reqLoad;
                busy.push({completionTime, assignedServer});
            }
            int maxRequests = *max_element(count.begin(), count.end());
            vector<int> res;
            for(int i = 0; i < k; i++){
                if(count[i] == maxRequests){
                    res.push_back(i);
                }
            }
            return res;
        }
    };