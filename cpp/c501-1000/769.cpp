class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
           int ch = 0;
           int cm = 0;
           for(int i = 0; i < arr.size(); i++){
            cm = max(cm, arr[i]);
            if(cm == i){
                ch++;
            }
           } 
           return ch;
        }
    };