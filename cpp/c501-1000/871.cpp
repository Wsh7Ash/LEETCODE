class Solution {
    public:
        int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
            priority_queue<int> heap;
            int res =0;
            int i = 0;
            int cur = startFuel;
            int n = stations.size();
    
            while(cur < target){
                while(i < n && stations[i][0] <= cur){
                    heap.push(stations[i][1]);
                    i++;
                }
                if(heap.empty()) return -1;
    
                cur += heap.top();
                heap.pop();
                res++;
    
            }
            return res;
        }
    };