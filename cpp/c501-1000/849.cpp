class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            int n = seats.size();
            int l = -1;
            int md = 0;
            for(int i = 0; i < n; i++){
                if(seats[i] == 1){
                    if(l == -1){
                        md = max(md, i);
                    }else{
                        md = max(md, (i - l) / 2);
                    }
                    l = i;
                }
            }
            md = max(md, n-1-l);
            return md;
        }
    };