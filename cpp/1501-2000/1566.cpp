class Solution {
    public:
        bool containsPattern(vector<int>& arr, int m, int k) {
            int n = arr.size();
            int count = 0;
            for(int i = 0; i < n - m; i++){
                if(arr[i] == arr[i+m]){
                    count++;
                }else{count = 0;}
                if(count >= m * (k - 1)){
                    return true;
                }
            }
            return false;
        }
    };