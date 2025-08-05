class Solution {
    public:
        int videoStitching(vector<vector<int>>& clips, int time) {
           sort(clips.begin(), clips.end(), [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0] || (a[0]== b[0] && a[1] > b[1]);
           }); 
    
           int ce = 0;
           int ne = 0;
           int c = 0;
           int i = 0;
           int n = clips.size();
    
           while(ce < time){
            while(i < n && clips[i][0] <= ce){
                ne = max(ne, clips[i][1]);
                i++;
            }
            if(ce == ne) return -1;
    
            ce = ne;
            c++;
           }
           return c;
        }
    };