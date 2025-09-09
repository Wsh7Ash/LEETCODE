class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        map<int, int> dp;
        dp[arr1[0]] = 0;

        for(int x : arr2){
            if(x != arr1[0]){
                if(dp.find(x) == dp.end()){
                    dp[x] = 1;
                }else{
                    dp[x] = min(dp[x], 1);
                }
            }
        }

        for(int i = 1; i < n; i++){
            map<int, int> new_dp;
            for(auto& [val, cost] : dp){
                if(arr1[i] > val){
                    if(new_dp.find(arr1[i]) == new_dp.end()){
                        new_dp[arr1[i]] = cost;
                    }else{
                        new_dp[arr1[i]] = min(new_dp[arr1[i]], cost);
                    }
                }

                auto it = upper_bound(arr2.begin(), arr2.end(), val);
                if(it != arr2.end()){
                    int candidate = *it;
                    if(new_dp.find(candidate) == new_dp.end()){
                        new_dp[candidate] = cost + 1;
                    }else{
                        new_dp[candidate] = min(new_dp[candidate], cost + 1);
                    }
                }
            }
            dp = new_dp;
            if(dp.empty()) return -1;
        }

        int res = INT_MAX;
        for(auto& [val, cost] : dp){
            res = min(res, cost);
        }
        return res;
    }
};