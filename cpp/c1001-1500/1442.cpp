class Solution {
    public:
        int countTriplets(vector<int>& arr) {
            int n = arr.size();
            int count = 0;
    
            for(int i = 0; i < n; i++){
                int xor_val = 0;
                for(int k = i; k < n; k++){
                    xor_val ^= arr[k];
    
                    if(xor_val == 0){
                        count += (k - i);
                    }
                }
            }
            return count;
        }
    };