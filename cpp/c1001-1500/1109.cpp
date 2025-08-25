class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            vector<int> res(n, 0);
            for(const auto& b : bookings){
                int f = b[0];
                int l = b[1];
                int s = b[2];
                res[f - 1] += s;
                if(l < n) res[l] -= s;
            }
    
            for(int i = 1; i < n; i++) res[i] += res[i-1];
            return res;
        }
    };