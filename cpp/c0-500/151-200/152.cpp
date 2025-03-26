#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxProduct = nums[0], minProduct = nums[0], globalMax = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxProduct, minProduct); // Swap because a negative number flips min/max
            }
            
            maxProduct = max(nums[i], nums[i] * maxProduct);
            minProduct = min(nums[i], nums[i] * minProduct);
            
            globalMax = max(globalMax, maxProduct);
        }
        
        return globalMax;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Output: " << sol.maxProduct(nums1) << endl; // Output: 6

    vector<int> nums2 = {-2, 0, -1};
    cout << "Output: " << sol.maxProduct(nums2) << endl; // Output: 0

    vector<int> nums3 = {1, -2, -3, 0, 7, -8, -2};
    cout << "Output: " << sol.maxProduct(nums3) << endl; // Output: 112

    return 0;
}
