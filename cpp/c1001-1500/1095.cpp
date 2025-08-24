/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

 class Solution {
    public:
        int findInMountainArray(int target, MountainArray &mountainArr) {
            int n = mountainArr.length();
            int left = 0, right = n - 1;
            int peak = 0;
    
            while(left < right){
                int mid = left + (right - left) / 2;
                int midVal = mountainArr.get(mid);
                int nextVal = mountainArr.get(mid + 1);
                if(midVal < nextVal) left = mid + 1;
                else right = mid;
            }
            peak = left;
    
            left = 0; 
            right = peak;
            while(left <= right){
                int mid = left + (right - left) / 2;
                int midVal =mountainArr.get(mid);
                if(midVal == target) return mid;
                else if(midVal < target) left = mid + 1;
                else right = mid - 1;
            }
    
            left = peak;
            right = n - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                int midVal = mountainArr.get(mid);
                if(midVal == target) return mid;
                else if(midVal > target) left = mid + 1;
                else right = mid - 1;
            }
            return -1;
        }
    };