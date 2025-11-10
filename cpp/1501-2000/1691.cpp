class Solution {
    public:
        int maxHeight(vector<vector<int>>& cuboids) {
            int n = cuboids.size();
    
            for(auto& cuboid : cuboids){
                sort(cuboid.begin(), cuboid.end());
            }
            sort(cuboids.begin(), cuboids.end());
            vector<int> dp(n, 0);
            for(int i = 0; i < n; i++){
                dp[i] = cuboids[i][2];
            }
            for(int i = 1; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(canPlace(cuboids[j], cuboids[i])){
                        dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                    }
                }
            }
            return *max_element(dp.begin(), dp.end());
        }
    private:
        bool canPlace(vector<int>& a, vector<int>& b){
            return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
        }
    };