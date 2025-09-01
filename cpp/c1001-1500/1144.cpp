class Solution {
    public:
        int movesToMakeZigzag(vector<int>& nums) {
            int n = nums.size();
            int m1 = 0;
            int m2 = 0;
    
            vector<int> arr1 = nums;
            for(int i = 0; i < n; i+=2){
                if(i-1 >= 0 && arr1[i] <= arr1[i-1]){
                    m1 += arr1[i-1] - arr1[i] + 1;
                    arr1[i-1] = arr1[i] - 1;
                }
                if(i+1 < n && arr1[i] <= arr1[i+1]){
                    m1 += arr1[i+1] - arr1[i] + 1;
                    arr1[i+1] = arr1[i] - 1;
                }
            }
            
            vector<int> arr2 = nums;
            for(int i = 1; i < n; i+=2){
                if(i-1 >= 0 && arr2[i] <= arr2[i-1]){
                    m2 += arr2[i-1] - arr2[i] + 1;
                    arr2[i-1] = arr2[i] - 1;
                }
                if(i+1 < n && arr2[i] <= arr2[i+1]){
                    m2 += arr2[i+1] - arr2[i] + 1;
                    arr2[i+1] = arr2[i] - 1;
                }
            }
    
            return min(m1, m2);
        }
    };