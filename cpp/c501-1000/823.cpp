class Solution {
    public:
        int numFactoredBinaryTrees(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            sort(arr.begin(), arr.end());
            unordered_map<int, long> dp;
            for(int num : arr){
                dp[num] = 1;
            }
    
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < i; j++){
                    if(arr[i] % arr[j] == 0){
                        int comp = arr[i] / arr[j];
                        if(dp.count(comp)){
                            dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[comp]) % MOD;
                        }
                    }
                }
            }
            long res = 0;
            for(auto& e : dp){
                res = (res + e.second) % MOD;
            }
            return res;
        }
    };class Solution {
        public:
            int numFactoredBinaryTrees(vector<int>& arr) {
                const int MOD = 1e9 + 7;
                sort(arr.begin(), arr.end());
                unordered_map<int, long> dp;
                for(int num : arr){
                    dp[num] = 1;
                }
        
                for(int i = 0; i < arr.size(); i++){
                    for(int j = 0; j < i; j++){
                        if(arr[i] % arr[j] == 0){
                            int comp = arr[i] / arr[j];
                            if(dp.count(comp)){
                                dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[comp]) % MOD;
                            }
                        }
                    }
                }
                long res = 0;
                for(auto& e : dp){
                    res = (res + e.second) % MOD;
                }
                return res;
            }
        };class Solution {
            public:
                int numFactoredBinaryTrees(vector<int>& arr) {
                    const int MOD = 1e9 + 7;
                    sort(arr.begin(), arr.end());
                    unordered_map<int, long> dp;
                    for(int num : arr){
                        dp[num] = 1;
                    }
            
                    for(int i = 0; i < arr.size(); i++){
                        for(int j = 0; j < i; j++){
                            if(arr[i] % arr[j] == 0){
                                int comp = arr[i] / arr[j];
                                if(dp.count(comp)){
                                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[comp]) % MOD;
                                }
                            }
                        }
                    }
                    long res = 0;
                    for(auto& e : dp){
                        res = (res + e.second) % MOD;
                    }
                    return res;
                }
            };class Solution {
                public:
                    int numFactoredBinaryTrees(vector<int>& arr) {
                        const int MOD = 1e9 + 7;
                        sort(arr.begin(), arr.end());
                        unordered_map<int, long> dp;
                        for(int num : arr){
                            dp[num] = 1;
                        }
                
                        for(int i = 0; i < arr.size(); i++){
                            for(int j = 0; j < i; j++){
                                if(arr[i] % arr[j] == 0){
                                    int comp = arr[i] / arr[j];
                                    if(dp.count(comp)){
                                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[comp]) % MOD;
                                    }
                                }
                            }
                        }
                        long res = 0;
                        for(auto& e : dp){
                            res = (res + e.second) % MOD;
                        }
                        return res;
                    }
                };