class Solution {
    public:
        vector<int> getStrongest(vector<int>& arr, int k) {
            sort(arr.begin(), arr.end());
            int n = arr.size();
            int median = arr[(n - 1) / 2];
    
            vector<int> res;
            int left = 0, right = n - 1;
    
            while(k > 0){
                int ls = abs(arr[left] - median);
                int rs = abs(arr[right] - median);
                if(rs >= ls){
                    res.push_back(arr[right]);
                    right--;
                }else{
                    res.push_back(arr[left]);
                    left++;
                }
                k--;
            }
            return res;
            }
    };