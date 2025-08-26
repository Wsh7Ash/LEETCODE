class Solution {
    public:
        vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
            int n_skills = req_skills.size();
            int n_people = people.size();
            unordered_map<string, int> skill_to_bit;
            for(int i = 0; i < n_skills; i++){
                skill_to_bit[req_skills[i]] = i;
            }
    
            vector<int> people_skills(n_people, 0);
            for(int i = 0; i < n_people; i++){
                for(const string& skill : people[i]){
                    if(skill_to_bit.find(skill) != skill_to_bit.end()){
                        people_skills[i] |= (1 << skill_to_bit[skill]);
                    }
                }
            }
    
            int total_mask = (1 << n_skills) - 1;
            vector<long long> dp(1 << n_skills, (1LL << n_people) - 1);
            dp[0] = 0;
    
            for(int i = 0; i < n_people; i++){
                int skills = people_skills[i];
                if(skills == 0) continue;
                for(int mask = total_mask; mask >= 0; mask--){
                    int new_mask = mask | skills;
                    if(__builtin_popcountll(dp[new_mask]) > __builtin_popcountll(dp[mask] | (1LL << i))){
                        dp[new_mask] = dp[mask] | (1LL << i);
                    }
                }
            }
    
            long long team_mask = dp[total_mask];
            vector<int> res;
            for(int i = 0; i < n_people; i++){
                if(team_mask & (1LL << i)){
                    res.push_back(i);
                }
            }
            return res;
        }
    };