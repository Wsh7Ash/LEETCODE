double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;

        while(low <= high){
            int pX = (low + high) / 2;
            int pY = (x + y + 1) / 2 - pX;

            int maxLeftX = (pX == 0) ? INT_MIN : nums1[pX - 1];
            int minRightX = (pX == x) ? INT_MAX : nums1[pX];

            int maxLeftY = (pY == 0) ? INT_MIN : nums2[pY - 1];
            int minRightY = (pY == y) ? INT_MAX : nums2[pY];

            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((x + y) % 2 == 0) return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                else return max(maxLeftX, maxLeftY);
            }else if(maxLeftX > minRightY){
                high = pX - 1;
            }else{
                 low = pX + 1;
            }
        }
        throw invalid_argument("");
    }