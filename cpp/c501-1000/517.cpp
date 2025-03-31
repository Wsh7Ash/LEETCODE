class Solution {
    public:
        int findMinMoves(vector<int>& machines) {
            int total = accumulate(machines.begin(), machines.end(), 0);
            int n = machines.size();
            if(total % n != 0) return -1;
            int target = total / n;
            int moves = 0;
            int balance = 0;
            for(int dresses : machines){
                balance += dresses - target;
                moves = max(moves, max(abs(balance), dresses - target));
            }
            return moves;
        }
    };