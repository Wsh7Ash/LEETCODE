class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int expected = 1;
            int i = 0;
    
            while(k > 0){
                if(i < arr.size() && arr[i] == expected){
                    i++;
                }else{k--;}
                expected++;
            }
            return expected - 1;
        }
    };