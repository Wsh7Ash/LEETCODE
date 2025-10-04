class Solution {
    public:
        vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    
            int n = friends.size();
            vector<bool> visited(n, false);
            queue<int> q;
    
            q.push(id);
            visited[id] = true;
    
            for(int l = 0; l < level; l++){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    int cur = q.front();
                    q.pop();
    
                    for(int fId : friends[cur]){
                        if(!visited[fId]){
                            visited[fId] = true;
                            q.push(fId);
                        }
                    }
                }
            }
            
            unordered_map<string, int> videoCount;
            while(!q.empty()){
                int fId = q.front();
                q.pop();
                for(const string& video : watchedVideos[fId]){
                    videoCount[video]++;
                }
            }
    
            vector<pair<int, string>> videoList;
            for(const auto& entry : videoCount){
                videoList.push_back({entry.second, entry.first});
            }
    
            sort(videoList.begin(), videoList.end(), [](const pair<int, string>& a, const pair<int, string>& b){
                if(a.first != b.first){
                    return a.first < b.first;
                }
                return a.second < b.second;
            });
    
            vector<string> res;
            for(const auto& entry :  videoList){
                res.push_back(entry.second);
            }
            return res;
        }
    };