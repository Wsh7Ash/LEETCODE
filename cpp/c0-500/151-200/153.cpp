#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;  // Minimum is in the right half
            } else {
                right = mid;  // Minimum is in the left half or at mid
            }
        }
        
        return nums[left];  // or nums[right], both are the minimum
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {3,4,5,1,2};
    cout << "Output: " << sol.findMin(nums1) << endl; // Output: 1

    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << "Output: " << sol.findMin(nums2) << endl; // Output: 0

    vector<int> nums3 = {11,13,15,17};
    cout << "Output: " << sol.findMin(nums3) << endl; // Output: 11

    return 0;
}
