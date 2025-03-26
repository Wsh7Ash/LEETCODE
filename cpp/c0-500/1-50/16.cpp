 int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return sum;

                int diff = abs(target - sum);
                if(diff < minDiff){
                    minDiff = diff;
                    closestSum = sum;
                }

                if(sum < target){
                    l++;
                }else{
                    r--;
                }
            } 
        }
        return closestSum;

    }