class Solution {
    public:
        char slowestKey(vector<int>& releaseTimes, string keysPressed) {
            char res = keysPressed[0];
            int md = releaseTimes[0];
            for(int i = 1; i < releaseTimes.size(); i++){
                int d = releaseTimes[i] - releaseTimes[i-1];
                if(d > md || (d == md && keysPressed[i] > res)){
                    md = d;
                    res = keysPressed[i];
                }
            }
            return res;
        }
    };