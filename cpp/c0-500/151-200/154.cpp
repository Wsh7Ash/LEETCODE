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
                left = mid + 1; // Min is in the right half
            } else if (nums[mid] < nums[right]) {
                right = mid; // Min is in the left half or at mid
            } else {
                right--; // nums[mid] == nums[right], move right pointer
            }
        }

        return nums[left]; // or nums[right], both point to the minimum
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {1,3,5};
    cout << "Output: " << sol.findMin(nums1) << endl; // Output: 1

    vector<int> nums2 = {2,2,2,0,1};
    cout << "Output: " << sol.findMin(nums2) << endl; // Output: 0

    vector<int> nums3 = {4,4,5,6,7,0,1,4};
    cout << "Output: " << sol.findMin(nums3) << endl; // Output: 0

    return 0;
}
