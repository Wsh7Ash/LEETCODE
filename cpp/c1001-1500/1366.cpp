class Solution {
    public:
        string rankTeams(vector<string>& votes) {
            
            if(votes.empty()) return "";
    
            int numTeams = votes[0].length();
    
            unordered_map<char,  vector<int>> voteCounts;
    
            for(char team : votes[0]){
                voteCounts[team] = vector<int>(numTeams, 0);
            }
    
            for(const string& vote : votes){
                for(int i = 0; i < vote.length(); i++){
                    voteCounts[vote[i]][i]++;
                }
            }
    
            vector<pair<char, vector<int>>> teams(voteCounts.begin(), voteCounts.end());
    
            sort(teams.begin(), teams.end(), [&](const pair<char, vector<int>>& a, const pair<char, vector<int>>& b){
                for(int i = 0; i < numTeams; i++){
                    if(a.second[i] != b.second[i]){
                        return a.second[i] > b.second[i];
                    }
                }
                return a.first < b.first;
            });
    
            string res = "";
            for(const auto& team : teams){
                res += team.first;
            }
            return res;
        }
    };