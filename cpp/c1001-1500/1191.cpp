class Solution {
    public:
        int kConcatenationMaxSum(vector<int>& arr, int k) {
            const int MOD = 1e9 + 7;
            int n = arr.size();
    
            long long max_ending_here = 0;
            long long max_so_far = 0;
    
            for(int i = 0; i < n; i++){
                max_ending_here = max((long long)arr[i], max_ending_here + arr[i]);
                max_so_far = max(max_so_far, max_ending_here);
            }
    
            if(k == 1) return max_so_far % MOD;
    
            long long total_sum = 0;
            for(int num : arr){
                total_sum += num;
            }
    
            if(total_sum > 0 && max_so_far == total_sum) return (total_sum * k) % MOD;
    
            long long prefix_sum = 0, max_prefix = 0;
            long long suffix_sum = 0, max_suffix = 0;
    
            for(int i = 0; i < n; i++){
                prefix_sum += arr[i];
                max_prefix = max(max_prefix, prefix_sum);
            }
            for(int i = n -1; i >= 0; i--){
                suffix_sum += arr[i];
                max_suffix = max(max_suffix, suffix_sum);
            }
    
            long long o1 = max_so_far;
            long long o2 = max_suffix + max_prefix;
            long long o3 = (k > 2) ? max_suffix + total_sum * (k - 2) + max_prefix : 0;
    
            long long res = max({o1, o2, o3, 0LL});
    
            return res % MOD;
        }
    };