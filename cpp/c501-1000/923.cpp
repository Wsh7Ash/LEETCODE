class Solution {
    public:
        int threeSumMulti(vector<int>& arr, int target) {
            const int MOD = 1e9 + 7;
            sort(arr.begin(), arr.end());
            int n = arr.size();
            long res = 0;
    
            for(int i = 0; i < n; i++){
                int l = i + 1;
                int r = n - 1;
                int new_target = target - arr[i];
    
                while(l < r){
                    int sum = arr[l] + arr[r];
                    if(sum < new_target){
                        l++;
                    }else if(sum > new_target){
                        r--;
                    }else{
                        if(arr[l] != arr[r]){
                            int left_count = 1;
                            int right_count = 1;
    
                            while(l + 1 < r && arr[l] == arr[l + 1]){
                                l++;
                                left_count++;
                            }
                            while(r - 1 > l && arr[r] == arr[r - 1]){
                                r--;
                                right_count++;
                            }
                            res += left_count * right_count;
                            res %= MOD;
                            l++;
                            r--;
                        }else{
                            int count = r - l + 1;
                            res += count *(count - 1)/2;
                            res %= MOD;
                            break;
                        }
                    }
                }
            }
            return res;
        }
    };