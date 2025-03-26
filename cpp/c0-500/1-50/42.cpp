class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int l = 0, r = n - 1;
        int l_max = height[l], r_max = height[r];
        int result = 0;

        while(l < r){
            if(height[l] < height[r]){
                l++;
                l_max = max(l_max, height[l]);
                result += max(0, l_max - height[l]);
            }else{
                r--;
                r_max = max(r_max, height[r]);
                result += max(0, r_max - height[r]);
            }
        }
        return result;

    }
};