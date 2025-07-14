class TopVotedCandidate {
    public:
        vector<int> times;
        vector<int> leaders;
    
        TopVotedCandidate(vector<int>& persons, vector<int>& times) {
            this->times = times;
            unordered_map<int, int> voteCount;
            int curLeader = -1;
            int maxVotes = 0;
            leaders.resize(persons.size());
    
            for(int i = 0; i < persons.size(); i++){
                int person = persons[i];
                voteCount[person]++;
                if(voteCount[person] >= maxVotes){
                    maxVotes = voteCount[person];
                    curLeader = person;
                }
                leaders[i] = curLeader;
            }    
        }
        
        int q(int t) {
            int left = 0;
            int right = times.size() - 1;
            int bestIndex = 0;
            
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(times[mid] <= t){
                    bestIndex = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return leaders[bestIndex];
    
        }
    };
    
    /**
     * Your TopVotedCandidate object will be instantiated and called as such:
     * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
     * int param_1 = obj->q(t);
     */