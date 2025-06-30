class Solution {
    public:
        int bestRotation(vector<int>& nums) {
            int n = nums.size();
            vector<int> change(n + 1, 0);
            for(int i = 0; i < n; i++){
                int num = nums[i];
                if(num <= i){
                    int left = 0;
                    int right = i - num;
                    change[left] += 1;
                    if(right + 1 <= n - 1){
                        change[right + 1] -= 1; 
                    }
    
                    left = i + 1;
                    right = n - 1;
                    if(left <= right){
                        change[left] += 1;
                        if(right + 1 <= n - 1){
                            change[right + 1] -= 1;
                        }
                    }
                }else{
                        int left = i+1;
                        int right = i + n - num;
                        if(left <= right){
                            change[left] += 1;
                            if(right + 1 <= n-1){
                                change[right + 1] -= 1;
                            }
                        }
                    }
            }
            int bestk = 0;
            int maxs = 0;
            int curs = 0;
            for(int k = 0; k < n; k++){
                curs += change[k];
                if(curs > maxs){
                    maxs = curs;
                    bestk = k;
                }else if(curs == maxs && k < bestk) bestk = k;
            }
            return bestk;
        }
    };