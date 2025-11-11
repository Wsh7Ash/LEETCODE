class Solution {
    public:
        double averageWaitingTime(vector<vector<int>>& customers) {
            long long totalWaitingTime = 0;
            int curTime = 0;
    
            for(const auto& customer : customers){
                int arrival = customer[0];
                int cookTime = customer[1];
                curTime = max(curTime, arrival) + cookTime;
                totalWaitingTime += curTime - arrival;
            }
            return (double)totalWaitingTime / customers.size();
        }
    };