class Solution {
    public:
        int getWinner(vector<int>& arr, int k) {
            int cur_winner = arr[0];
            int win_count = 0;
    
            for(int i = 1; i < arr.size(); i++){
                if(arr[i] > cur_winner){
                    cur_winner = arr[i];
                    win_count = 1;
                }else{
                    win_count++;
                }
                if(win_count == k) return cur_winner;
            }
            return cur_winner;
        }
    };