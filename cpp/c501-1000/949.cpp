class Solution {
    public:
        string largestTimeFromDigits(vector<int>& arr) {
            string res;
            int max_time = -1;
    
            sort(arr.begin(), arr.end());
            do{
                int hours = arr[0] * 10 + arr[1];
                int minutes = arr[2] * 10 + arr[3];
    
                if(hours < 24 && minutes < 60){
                    int total_minutes = hours * 60 + minutes;
                    if(total_minutes > max_time){
                        max_time = total_minutes;
                        stringstream ss;
                        ss << setw(2) << setfill('0') << hours << ":"
                           << setw(2) << setfill('0') << minutes;
                        res = ss.str(); 
                   }
                }
    
            }while(next_permutation(arr.begin(), arr.end()));
            return max_time == -1 ? "": res;
        }
    };