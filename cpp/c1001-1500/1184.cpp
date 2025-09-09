class Solution {
    public:
        int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
            int n = distance.size();
            vector<int> prefix(n+1, 0);
            for(int i = 1; i <=n; i++){
                prefix[i] = prefix[i-1] + distance[i-1];
            }
    
            int total = prefix[n];
            int clockwise;
            if(start <= destination){
                clockwise = prefix[destination] - prefix[start];
            }else{
                clockwise = prefix[n] - prefix[start] + prefix[destination];
            }
    
            int counterclockwise = total - clockwise;
    
            return min(clockwise, counterclockwise);
        }
    };